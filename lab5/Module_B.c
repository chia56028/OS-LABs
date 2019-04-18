// Module_B.c
#include <linux/module.h>

extern int symbol_variable;
extern int symbol_function(int);
int symbol_variable_B = 56;

int init_module(void)
{
	printk(KERN_INFO "Module_B inserts successfully\n");
	printk(KERN_INFO "symbol_varible:%d\n",symbol_variable);

	printk(KERN_INFO "symbol_function(100) = %d\n",symbol_function(100));
	printk(KERN_INFO "symbol_function(0) = %d\n",symbol_function(0));
	printk(KERN_INFO "symbol_function(-100) = %d\n",symbol_function(-100));
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Module_B removes successfully\n");
}


EXPORT_SYMBOL(symbol_variable_B);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");
