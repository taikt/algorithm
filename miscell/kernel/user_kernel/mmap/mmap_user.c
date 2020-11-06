/*
 * 
 */
#include "mmap_kernel.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <unistd.h>		/* exit */
#include <sys/ioctl.h>		/* ioctl */

#include <sys/mman.h>
#include <string.h>
#include<errno.h>


/* 
 * Functions for the ioctl calls 
 */

ioctl_set_msg(int file_desc, char *message)
{
	int ret_val;

	ret_val = ioctl(file_desc, IOCTL_SET_MSG, message);

	if (ret_val < 0) {
		printf("ioctl_set_msg failed:%d\n", ret_val);
		exit(-1);
	}
}

ioctl_get_msg(int file_desc)
{
	int ret_val;
	char message[100];

	/* 
	 * Warning - this is dangerous because we don't tell
	 * the kernel how far it's allowed to write, so it
	 * might overflow the buffer. In a real production
	 * program, we would have used two ioctls - one to tell
	 * the kernel the buffer length and another to give
	 * it the buffer to fill
	 */
	ret_val = ioctl(file_desc, IOCTL_GET_MSG, message);

	if (ret_val < 0) {
		printf("ioctl_get_msg failed:%d\n", ret_val);
		exit(-1);
	}

	printf("get_msg message:%s\n", message);
}

ioctl_get_nth_byte(int file_desc)
{
	int i;
	char c;

	printf("get_nth_byte message:");

	i = 0;
	do {
		c = ioctl(file_desc, IOCTL_GET_NTH_BYTE, i++);

		if (c < 0) {
			printf
			    ("ioctl_get_nth_byte failed at the %d'th byte:\n",
			     i);
			exit(-1);
		}

		putchar(c);
	} while (c != 0);
	putchar('\n');
}

/* 
 * Main - Call the ioctl functions 
 */
main()
{
	int fd, ret;
	char *msg = "Hello world\n";
	char *p = NULL;
    char buff[64];

	fd = open(DEVICE_FILE_NAME, 0);
	if (fd < 0) {
		printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
		exit(-1);
	}
    printf("fd=%d\n",fd);
    ioctl_set_msg(fd, msg);
	ioctl_get_msg(fd);
    if(fd >= 0) {
       p = (char*)mmap(0,4096,PROT_READ | PROT_WRITE,MAP_PRIVATE,fd,0); // MAP_SHARED wrong in VM
       if (p == MAP_FAILED) {
           perror("mmap fail");
           goto out;
       } 
       printf("memory map: %s\n", p);
       munmap(p, 4096);

       close(fd);
   } else printf("error fd=%d\n",fd);

#if 0
TODO: fix write error       
   fd = open(DEVICE_FILE_NAME, O_RDWR);
    ret = write(fd, "abcd", strlen("abcd"));
    if (ret < 0) {
        printf("write error!\n");
        ret = errno;
        goto out;
    }

    ret = read(fd, buff, 64);
    if (ret < 0) {
        printf("read error!\n");
        ret = errno;
        goto out;
    }

    printf("read: %s\n", buff);
	
    close(fd);
#endif
out:
    return ret;

}
