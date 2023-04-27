#include "shell.h"

/**
 * stat_error - Prints error status
 * @n: number to print
 *
 * Return: an integer highlighting the error.
 */
int stat_error(int n)
{

	unsigned int num;
	int i = 0;

	if (n < 0)
	{
		num = -n;
		i = i + _putchar('-');
	}
	else
		num = n;

	if (num / 10 != '\0')
		i = i + stat_error(num / 10);

	i = i + _putchar(num % 10 + '0');

	return (i);
}
