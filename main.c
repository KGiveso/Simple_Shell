#include "shell.h"#include "shell.h"

/**
 * _free - frees array and its elements
 * @args: array to free
 */
void _free(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i++]);
	}
	free(args);
}

/**
 * main - runs UNIX interpreter
 * @ac: number of arguments passed
 * @av: array of arguments;
 * Return: 0 (success)
 */
int main(int ac, char **av)
{
	char *cmd = NULL, **args;
	size_t n = 0;
	ssize_t line;
	int max_args;

	if (ac < 1)
		return (1);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(2, "$ ", _strlen("$ "));
			fflush(stdout);
		}

		line = getline(&cmd, &n, stdin);
		if (line == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				write(2, "\n", _strlen("\n"));
			}
			break;
		}

		cmd[line - 1] = '\0';

		exit_env(cmd);

		args = tokenize(cmd, " ", &max_args);
		child_process(args);
	}
	_free(args);
	free(cmd);
	return (0);
}
