#include "shell.h"
/**
 * _inputs - Fill an array with every input from user
 * @in: input String
 * @strings: input array to be filled
 * Return: Length of the array
 */

int _inputs(char *in, char **strings)
{
	int i = 0;
	char *options, *aux = in, *instruct;

	instruct = strtok(in, "\n\t\r ");
	strings[i] = instruct;
	while (aux != NULL)
	{
		++i;
		options = strtok(NULL, "\n\t\r ");
		aux = options;
		strings[i] = options;
	}
	strings[i] = NULL;
	return (i);
}
