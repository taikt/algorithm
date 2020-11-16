#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/init.h> 
 
static void create_oops_(void) { 
    *(int *)0 = 0; 
    //int a = 1;
    //panic("my message: taikt create panic");
} 
 
static int __init my_oops_init(void) { 
    printk("taikt oops from the module\n"); 
    create_oops_(); 
    return (0); 
} 
static void __exit my_oops_exit(void) { 
    printk("Goodbye world\n"); 
} 
 
module_init(my_oops_init); 
module_exit(my_oops_exit);
