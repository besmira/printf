#include "main.h"
#include <stdio.h>

/**
 * main - call _printf
 * Return: 0
 */
int main(void)
{
	char *test = "test";
	char test2 = 'c';
	char *string = "this is a vary long string and it contains a long text";

	_printf("testing c %% %s, %c, %s \n", test, test2, string);
	return (0);
}
