#include "shell.h"
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
