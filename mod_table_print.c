#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <uapi/asm-generic/unistd.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Hatam-Sapa");
MODULE_DESCRIPTION("Syscall for dummies...");
MODULE_VERSION("0.1.0");

unsigned long *syscall_table = (unsigned long *)0xffffffff81c00240;

static int __init table_print_init(void)
{
    int i = 0;

    printk(KERN_INFO "SYMBOL TABLE ENTRY POINT IS: %p\n", syscall_table);
    while (i < __NR_syscalls)
    {
        printk(KERN_INFO "Syscall #%d:\t %lx\n", i + 1, *(syscall_table + i));
        i++;
    }

    return 0;
}

static void __exit table_print_exit(void)
{
    printk(KERN_INFO "End of Tables Addresses\n");
}

module_init(table_print_init);
module_exit(table_print_exit);