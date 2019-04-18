// Module_A.c
#include <linux/module.h>

int symbol_variable = 99;
int symbol_function(int x)
{
	if(x>100)
		return 1;
	else if(x==100)
		return 0;
	else
		return -1;
}

int init_module(void)
{
	printk(KERN_INFO "Module_A inserts successfully\n");
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Module_A removes successfully\n");
}

EXPORT_SYMBOL(symbol_variable);
EXPORT_SYMBOL(symbol_function);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");
