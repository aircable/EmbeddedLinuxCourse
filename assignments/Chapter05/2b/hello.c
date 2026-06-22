// set tabstop=2 number nohlsearch
// Example# 2.1 .. Simple "Hello World!" module example 
// synopsis:
// 	init:
// 	exit:
// 	printk()

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h> // for current macro

// extern void printK(void *,int);

MODULE_AUTHOR("Me"); 
MODULE_LICENSE("GPL"); 	/* kernel isn't tainted .. SUSE noop */

int hello_init(void){
	printk(KERN_ALERT "Hello, world (PID=%d, comm=%s)\n", current->pid, current->comm);
	return 0;
}

void hello_exit(void){
	printk(KERN_ALERT "Goodbye, cruel world (PID=%d,comm=%s)\n",current->pid, current->comm);
}

module_init(hello_init);
module_exit(hello_exit);
