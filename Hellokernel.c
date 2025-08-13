//Hello Kernel
#include<linux/init.h>
#include<linux/module.h>

static int __init hello_init(void){
    printk(KERN_INFO "Hello Kernel..");
    return 0;
}
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye Kernel..");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("Simple hello kernel");
