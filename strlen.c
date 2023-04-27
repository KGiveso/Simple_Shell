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
