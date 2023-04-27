#include "shell.h"
/**
 * _builtin - Checks if user's command arguments are in builtins
 * @strings: Pointer to the array of command  arguments
 * @exit_stat: current exit status
 * Return: (-1) if the command is not a builtin.
 */
int _builtin(char **strings, int exit_stat)
{
	char *builtin[2] = {
		"exit",
		"env"
	};
	int i = 0;

	while (i < 2)
	{
		if (_strcmp(strings[0], builtin[i]) == 0)
			break;
		i++;
	}
	if (i == 2)
		return (-1);
	if (_strcmp(builtin[i], "exit") == 0)
	{
		free(strings[0]);
		exit(exit_stat);
	}
	if (_strcmp(builtin[i], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}
	return (0);
}
