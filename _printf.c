#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

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

	str1 = (char *) malloc(sizeof(char *) * strlen(form));

	l = checkArg(form);


	va_start(ap, form);
	/*
	for (i = 0; i <= l; i++)
	{
		while(form[j] != '\0')
		{
			if(form[j] != '%')
			{
				str1[j] = form[j];
				j++;
			}
			else if (form[j] == '%' && form[j + 1] == '%')
			{
				write(1, "%", 1);
				j = j + 2;
				break;
			}
			else if (form[j] == '%' && (form[j + 1] == 's' || form[j + 1] == 'c'))
			{
				
				j = advPutchar(form, va_arg(ap, char *), j);
				break;
			}
		}
	}
	*/

	for (i = 0; form[i] != '\0'; i++)
	{
		write(1, &form[i], 1);
	}
	va_end(ap);
	free(str1);
	return (0);
}
