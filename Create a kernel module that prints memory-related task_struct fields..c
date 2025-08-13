//Create a kernel module that prints memory-related task_struct fields.
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

static int __init taskmem_init(void) {
    struct mm_struct *mm = current->mm;
    printk(KERN_INFO "Process PID: %d\n", current->pid);
    printk(KERN_INFO "Total VM: %lu KB\n", mm->total_vm << (PAGE_SHIFT - 10));
    printk(KERN_INFO "RSS: %lu KB\n", get_mm_rss(mm) << (PAGE_SHIFT - 10));
    return 0;
}

static void __exit taskmem_exit(void) {
    printk(KERN_INFO "Exiting memory info module\n");
}

module_init(taskmem_init);
module_exit(taskmem_exit);

MODULE_LICENSE("GPL");
