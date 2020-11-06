/*
 * --capture key press --
 *  Status: worked
 *
 * sudo insmod intrpt1.ko
 * sudo cat /dev/etx_device
 * dmesg
 *  
 *
 * Ref:
 * https://stackoverflow.com/questions/33836541/linux-kernel-how-to-capture-a-key-press-and-replace-it-with-another-key
 * ftp://ftp.lpp.polytechnique.fr/jeandet/keep/sync/LINUX/interrupt/t3.pdf
 * http://www.cs.otago.ac.nz/cosc440/labs/lab08.pdf
 * https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-part-13-interrupt-example-program-
x-kernel/
 * http://www.infradead.org/~mchehab/kernel_docs/driver-api/usb/writing_usb_driver.html
 * https://stackoverflow.com/questions/39911846/source-code-of-keyboard-driver-of-linux
 * https://www.tldp.org/HOWTO/Unix-and-Internet-Fundamentals-HOWTO/devices.html
 * https://stackoverflow.com/questions/27865075/how-would-one-go-about-generating-artificial-interrupts-in-the-linux-kern
 *
 *
 * */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <asm/io.h>

#define KBD_IRQ             1       /* IRQ number for keyboard (i8042) */
#define KBD_DATA_REG        0x60    /* I/O port for keyboard data */
#define KBD_SCANCODE_MASK   0x7f
#define KBD_STATUS_MASK     0x80

static irqreturn_t kbd2_isr(int irq, void *dev_id)
{
    char scancode;

    scancode = inb(KBD_DATA_REG);
    /* NOTE: i/o ops take a lot of time thus must be avoided in HW ISRs */
    pr_info("Scan Code %x %s\n",
            scancode & KBD_SCANCODE_MASK,
            scancode & KBD_STATUS_MASK ? "Released" : "Pressed");

    return IRQ_HANDLED;
}

static int __init kbd2_init(void)
{
    return request_irq(KBD_IRQ, kbd2_isr, IRQF_SHARED, "kbd2", (void *)kbd2_isr);
}

static void __exit kbd2_exit(void)
{
    free_irq(KBD_IRQ, (void *)kbd2_isr);
}

module_init(kbd2_init);
module_exit(kbd2_exit);

MODULE_LICENSE("GPL");
