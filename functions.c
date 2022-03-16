#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * pc - putchar characters
 * @arg: list
 * Return: 1
 */
int pc(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}


/**
 * ps - putchar strings
 * @arg: argument
 * Return: i
 */
int ps(va_list arg)
{
	char *str;
	int i;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(nil)";
	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * pi - print integer
 * @arg: argument
 * Return: i
 */
int pi(va_list arg)
{
	int num, n, dig, last, exp, i = 1;

	n = va_arg(arg, int);
	exp = 1;
	last = n % 10;
	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		last = -last;
		num = -num;
		n = -n;
		i++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			i++;
		}
	}

	return (i);
}
