#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * _print - copy of printf
 * @form: string format to be printed
 * Return: 0;
 */
int _printf(const char *form, ...)
{
	int i, j = 0, k, l = 0;
	va_list ap;
	char *str1;

	for (k = 0; form[k] != '\0'; k++)
	{
		if (form[k] == '%')
		l++;
	}

	va_start(ap, form);
	for (i = 0; i <= l; i++)
	{
		str1 = va_arg(ap, char*);
		while (form[j] != '\0')
		{
			if (form[j] != '%')
			{
				write(1, &form[j], 1);
				j++;
			}
			else if (form[j] == '%' && form[j + 1] == 's')
			{
				write(1, str1, (strlen(str1)));
				j = j + 2;
				break;
			}
			else if (form[j] == '%' && form[j + 1] == 'c')
			{
				write(1, &str1, 1);
				j = j + 2;
				break;
			}
			else if (form[j] == '%' && form[j + 1] == '%')
			{
				write(1, "%", 1);
				j = j + 2;
				break;
			}
		}
	}
	va_end(ap);

	return (0);
}
