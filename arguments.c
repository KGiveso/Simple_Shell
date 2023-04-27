#include "shell.h"

char **tokenize(char *cmd, char *delim, int *tokens)
{
	char **args, *token;
	int i = 0;

	args = malloc(sizeof(char *) * 100);
	if (args == NULL)
		return (NULL);

	token = strtok(cmd, delim);
	while (token != NULL && i < 100)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(args[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	*tokens = i;
	args[i] = NULL;
	return (args);
}
