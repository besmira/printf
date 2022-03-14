#include "main.h"
#include <unistd.h>
#include <string.h>
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
 * advPutchar - advanced putchar
 * @form: string
 * @str1: arguments
 * @j: index
 * Return: index
 */
int advPutchar(const char *form, char *str1, int j)
{
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
		}
	}
	return (j);
}
