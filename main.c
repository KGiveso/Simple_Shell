#include "shell.h"

/**
 * main - runs a UNIX command line interpreter
 * Return: 0 (success)
 */

int main(void)
{
	char *cmd = NULL, *args[100];
	size_t n = 0;
	ssize_t line;
	int i;

	while (1)
	{
		printf("shell$ ");
		fflush(stdout);

		line = getline(&cmd, &n, stdin);
		if (line == -1)
		{
			printf("\n");
			break;
		}

		cmd[line - 1] = '\0';

		for (i = 0; i < 2; i++)
		{
			args[i] = cmd;
			cmd = NULL;
		}

		child_process(args);
	}
	free(cmd);
	return (0);
}
