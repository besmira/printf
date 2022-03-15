#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * checkArg - check if string needs arguments
 * @str: string
 * Return: number of arguments
 */
int checkArg(const char *str)
{
	int i, j = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%' && str[i + 1] != '%')
			j++;
	}
	if (j == 0)
		j++;

	return (j);
}

/**
 * _putchar - print a string
 * @str: string
 */
void _putchar(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
}

/**
 * advPutchar - advanced putchar
 * @form: string
 * @str1: arguments
 * @j: index
 * Return: index
 */
int advPutchar(const char *form, char *str1, int j)
{
	if (form[j] == '%' && form[j + 1] == 's')
	{
		_putchar(str1);
		j = j + 2;
	}
	else if (form[j] == '%' && form[j + 1] == 'c')
	{
		write(1, &str1, 1);
		j = j + 2;
	}
	return (j);
}
