#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * convert_value - an integer to another base
 * @param num
 * @param base
 * @return
 */
char *convert_value(unsigned int num, int base) 
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do 
	{
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

void _printf(char *format, ...)
{
	char *curr;
	unsigned int i;
	char *s;

	va_list arg;
	va_start(arg, format);
	for (curr = format; *curr != '\0'; curr++)
	{
		while (*curr != '%')
		{
			putchar(*curr);
			curr++;
		}

		curr++;
		
		switch (*curr)
		{
			case '%':
				putchar('%');
				break;
			case 'c':
				i = va_arg(arg, int);
				write(1, &i, 1);
				break;
			case 'd':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = -i;
					putchar('-');
				}
				char *dec = convert_value(i, 10);
				write(1, dec, strlen(dec));
				break;
			case 'i':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = -i;
					putchar('-');
				}
				char *integer = convert_value(i, 10);
				write(1, integer, strlen(integer));
				break;
			case 'o':
				i = va_arg(arg, unsigned int);
				char *oct = convert_value(i, 8);
				write(1, oct, strlen(oct));
				break;
			case 's':
				s = va_arg(arg, char *);
				write(1, s, strlen(s));
				break;
			case 'x':
				i = va_arg(arg, unsigned int);
				char *hex = convert_value(i, 8);
				write(1, hex, strlen(hex));
				break;
		}
	}
	va_and(arg);
}
