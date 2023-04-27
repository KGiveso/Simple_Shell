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

		char *token;

		token = strtok(cmd, " ");
		for (i = 0; token != NULL; i++)
			{
			args[i] = token;
			token = strtok(NULL, " ");
			}

	if (execvp(args[0], args) == -1)
		{
		perror("execvp");
		exit(1);
		}
	}
	free(cmd);
	return (0);
}

