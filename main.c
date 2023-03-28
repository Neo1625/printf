#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%]\n");
	_printf("Let's try to printf a simple sentence.\n");
	_printf("this is not a fmt spec %r here\n");
	_printf("Hello%\n");
	_printf("%Hell\n");
	_printf("%s\n");
	printf("%s\n");
	return (0);
}
