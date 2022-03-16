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
	va_list	arguments;
	const char *p;
	int num = 0;

	if (form == NULL)
		return (-1);

	va_start(arguments, form);

	for (p = form; *p; p++)
	{
		if (*p == '%' && *p + 1 == '%')
		{
			_putchar(*p), num++;
			continue;
		}
		else if (*p == '%' && *p + 1 != '%')
		{
			switch (*++p)
			{
				case 's':
					num += ps(arguments);
					break;
				case 'c':
					num += pc(arguments);
					break;
				case '%':
					_putchar('%'), num++;
					break;
				case '\0':
					return (-1);
				case 'i':
				case 'd':
					num += pi(arguments);
					break;
				default:
					_putchar('%'), _putchar(*p), num += 2;
			}
		}
		else
			_putchar(*p), num++;
	}
	va_end(arguments);
	return (num);
}
