#include "main.h"
#include <stdio.h>

/**
 * main - call _printf
 * Return: 0
 */
int main(void)
{
	char *test = "sdfsdfsdf";
	char test2 = 'c';

	_printf("testing c %% %s, %c \n", test, test2);
	return (0);
}
