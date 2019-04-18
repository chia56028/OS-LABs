// Module_C.c
#include <linux/module.h>

extern int symbol_variable_B;

module_param(symbol_variable_B, int, 0);
MODULE_PARM_DESC(symbol_variable_B, "Desciption of B");

int init_module(void)
{
	printk(KERN_INFO "Module_C inserts successfully\n");
	printk(KERN_INFO "symbol_varible_B:%d\n",symbol_variable_B);
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Module_C removes successfully\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");
