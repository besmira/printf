#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - mere imitation of printf
 * @form: string to be printed
 * Return: 0
 */
int _printf(const char *form, ...)
{
	int i, j = 0, l = 0;
	va_list ap;
	char *str1;

	l = checkArg(form);


	va_start(ap, form);
	for (i = 0; i <= l; i++)
	{
		str1 = va_arg(ap, char*);
		j = advPutchar(form, str1, j);
	}
	va_end(ap);

	return (0);
}
