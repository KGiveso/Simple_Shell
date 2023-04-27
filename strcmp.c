#include "shell.h"
/**
 * _strcmp - compares two strings
 * @cmd: first string.
 * @argv: second string.
 *
 * Return: 0 if s1 and s2 are equals,
 * and number > 0 if cmd is greater while number
 * number < 0 if argv is greater.
 */
int _strcmp(char *cmd, char *argv)
{

	int i = 0, rv = 0;

	while (rv == 0)
	{
		if ((*(cmd + i) == '\0') && (*(argv + i) == '\0'))
		break;
		rv = *(cmd + i) - *(argv + i);
		i++;
	}

	return (rv);

}
