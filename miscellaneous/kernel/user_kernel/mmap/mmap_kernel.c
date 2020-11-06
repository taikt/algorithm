/*
 *  memory mapping user space and kernel space
 *  
 *  sudo insmod mmap_kernel.ko
 *  mknod char_dev c 100 0
 *  build mmap_user.c
 *  ./a.out
 *
 *  Ref:
 *  https://jlmedina123.wordpress.com/2015/04/14/mmap-driver-implementation/
 *  http://wiki.tldp.org/kernel_user_space_howto
 *  https://github.com/blue119/kernel_user_space_interfaces_example
 *
 *
 */

#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module */
#include <linux/fs.h>
//#include <asm/uaccess.h>	/* for get_user and put_user */
#include <linux/uaccess.h>	/* for get_user and put_user */

#include "mmap_kernel.h"
#include <linux/device.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/slab.h>


#define SUCCESS 0
#define DEVICE_NAME "char_dev"
#define BUF_LEN 80
static char *sh_mem = NULL;
#define MAX_SIZE (PAGE_SIZE * 2)   /* max size mmaped to userspace */

//#define DEBUG  TODO hang if debug enabled
/* 
 * Is the device open right now? Used to prevent
 * concurent access into the same device 
 */
static int Device_Open = 0;

/* 
 * The message the device will give when asked 
 */
static char Message[BUF_LEN];

/* 
 * How far did the process reading the message get?
 * Useful if the message is larger than the size of the
 * buffer we get to fill in device_read. 
 */
static char *Message_Ptr;

/* 
 * This is called whenever a process attempts to open the device file 
 */
static int device_open(struct inode *inode, struct file *file)
{
#ifdef DEBUG
	printk(KERN_INFO "device_open(%p)\n", file);
#endif

	/* 
	 * We don't want to talk to two processes at the same time 
	 */
	if (Device_Open)
		return -EBUSY;

	Device_Open++;
	/*
	 * Initialize the message 
	 */
	Message_Ptr = Message;
	try_module_get(THIS_MODULE);
	return SUCCESS;
}

static int device_release(struct inode *inode, struct file *file)
{
#ifdef DEBUG
	printk(KERN_INFO "device_release(%p,%p)\n", inode, file);
#endif

	/* 
	 * We're now ready for our next caller 
	 */
	Device_Open--;

	module_put(THIS_MODULE);
	return SUCCESS;
}


static ssize_t device_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
    int ret;
    
    printk("device_read: Page_size =%d\n",MAX_SIZE/2);
    if (len > MAX_SIZE) {
        pr_info("read overflow!\n");
        ret = -EFAULT;
        goto out;
    }

    if (copy_to_user(buffer, sh_mem, len) == 0) {
        //pr_info("mchar: copy %u char to the user\n", len);
    	printk("mchar: copy %d char to the user\n", len);
        ret = len;
    } else {
        ret =  -EFAULT;
    }

out:
    return ret;
}

static ssize_t device_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
    int ret;
    
    //printk("device_write: %s\n",buffer);

    if (copy_from_user(sh_mem, buffer, len)) {
        pr_err("mchar: write fault!\n");
        ret = -EFAULT;
        goto out;
    }
    //pr_info("mchar: copy %d char from the user\n", len);
    printk("mchar: copy %d char from the user\n", len);
    ret = len;

out:
    return ret;
}

long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)                                   
{
	int i;
	char *temp;
	char ch;

	/* 
	 * Switch according to the ioctl called 
	 */
	switch (ioctl_num) {
	case IOCTL_SET_MSG:
		/* 
		 * Receive a pointer to a message (in user space) and set that
		 * to be the device's message.  Get the parameter given to 
		 * ioctl by the process. 
		 */
        printk("IOCTL_SET_MSG called\n");
		temp = (char *)ioctl_param;

		/* 
		 * Find the length of the message 
		 */
		get_user(ch, temp);
		for (i = 0; ch && i < BUF_LEN; i++, temp++)
			get_user(ch, temp);

		device_write(file, (char *)ioctl_param, i, 0);
		break;

	case IOCTL_GET_MSG:
		/* 
		 * Give the current message to the calling process - 
		 * the parameter we got is a pointer, fill it. 
		 */
        printk("IOCTL_GET_MSG called\n");
		i = device_read(file, (char *)ioctl_param, 99, 0);

		/* 
		 * Put a zero at the end of the buffer, so it will be 
		 * properly terminated 
		 */
		put_user('\0', (char *)ioctl_param + i);
		break;

	case IOCTL_GET_NTH_BYTE:
		/* 
		 * This ioctl is both input (ioctl_param) and 
		 * output (the return value of this function) 
		 */
        printk("IOCTL_GET_NTH_BYTE called\n");
		return Message[ioctl_param];
		break;
	}

	return SUCCESS;
}

/*  mmap handler to map kernel space to user space   
 * 
 */ 
static int mchar_mmap(struct file *filp, struct vm_area_struct *vma) 
{
    printk("mchar_mmap \n"); 
    int ret = 0; 
    struct page *page = NULL; 
    unsigned long size = (unsigned long)(vma->vm_end - vma->vm_start); 
 
    if (size > MAX_SIZE) { 
        ret = -EINVAL;
        goto out;
    }

    page = virt_to_page((unsigned long)sh_mem + (vma->vm_pgoff << PAGE_SHIFT));
    ret = remap_pfn_range(vma, vma->vm_start, page_to_pfn(page), size, vma->vm_page_prot);
    if (ret != 0) {
        goto out;
    }

out:
    return ret;
}



/* Module Declarations */

/* 
 * This structure will hold the functions to be called
 * when a process does something to the device we
 * created. Since a pointer to this structure is kept in
 * the devices table, it can't be local to
 * init_module. NULL is for unimplemented functions. 
 */
struct file_operations Fops = {
	.read = device_read,
	.write = device_write,
	.unlocked_ioctl = device_ioctl,
	.open = device_open,
	.release = device_release,	/* a.k.a. close */
    .mmap = mchar_mmap, // try to disable it and try mapping from user space => no file error
};

/* 
 * Initialize the module - Register the character device 
 */
int init_module()
{
	int ret_val;
	/* 
	 * Register the character device (atleast try) 
	 *
	ret_val = register_chrdev(MAJOR_NUM, DEVICE_NAME, &Fops);

	 
	 * Negative values signify an error 
	 
	if (ret_val < 0) {
		printk(KERN_ALERT "%s failed with %d\n",
		       "Sorry, registering the character device ", ret_val);
		return ret_val;
	}
    */
    register_chrdev(MAJOR_NUM, DEVICE_NAME, &Fops);

	printk(KERN_INFO "%s The major device number is %d.\n",
	       "Registeration is a success", MAJOR_NUM);
	printk(KERN_INFO "If you want to talk to the device driver,\n");
	printk(KERN_INFO "you'll have to create a device file. \n");
	printk(KERN_INFO "We suggest you use:\n");
	printk(KERN_INFO "mknod %s c %d 0\n", DEVICE_FILE_NAME, MAJOR_NUM);
	printk(KERN_INFO "The device file name is important, because\n");
	printk(KERN_INFO "the ioctl program assumes that's the\n");
	printk(KERN_INFO "file you'll use.\n");
	
	   /* init this mmap area */
   sh_mem = kmalloc(MAX_SIZE, GFP_KERNEL);
   if (sh_mem == NULL) {
       ret_val = -ENOMEM;
       goto out;
   }

   sprintf(sh_mem, "xyz\n");
out:
	return 0;
}

/* 
 * Cleanup - unregister the appropriate file from /proc 
 */
void cleanup_module()
{
	int ret;

	/* 
	 * Unregister the device 
	 */
	unregister_chrdev(MAJOR_NUM, DEVICE_NAME);

	/* 
	 * If there's an error, report it 
	 */
	if (ret < 0)
		printk(KERN_ALERT "Error: unregister_chrdev: %d\n", ret);
}
