//To retrieve and display jiffies in a kernel module.
#include<linux/init.h>
#include<linux/module.h>
#include<linux/jiffies.h>

static int __init jiffies_init(void)
{
    printk(KERN_INFO "Current Jiffies:%lu\n",jiffies);
    return 0;
}
static void __exit jiffies_exit(void)
{
    printk(KERN_INFO "Goodbye Jiffies\n");
}
module_init(jiffies_init);
module_exit(jiffies_exit);

MODULE_LICENSE("GPL");
