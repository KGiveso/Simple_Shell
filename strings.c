#include "shell.h"
/**
 * _strlen - Holds the length of string char *str
 * @std: string whose length is to be found
 *
 * Return: The length ot the string
 */

int _strlen(const char *std)
{
	int len = 0;

	if (std == NULL)
		return (0);

	while (std[len] != '\0')
		len++;
	return (len);
}

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

/**
 * _strdup - string duplicate
 * @std: Input String to be duplicated
 * Return: Pointer (dup) to the duplicated string
 */
char *_strdup(char *std)
{
	unsigned int k, len;
	char *dup;

	if (std == NULL)
		return (NULL);

	for (len = 0; std[len] != '\0'; len++)
		;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (k = 0; k <= len; k++)
	{
		dup[k] = std[k];
	}
	return (dup);
}
