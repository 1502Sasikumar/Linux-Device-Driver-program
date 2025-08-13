//To retrieve and print the current task’s PID inside a kernel module.
#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>

static int __init pid_init(void)
{
    printk(KERN_INFO "Current pid:%d\n",current->pid);
    return 0;
}
static void  __exit pid_exit(void)
{
    printk(KERN_INFO "Exiting Pid Module\n");
}

module_init(pid_init);
module_exit(pid_exit);

MODULE_LICENSE("GPL");
