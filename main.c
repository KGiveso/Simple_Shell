#include "shell.h"

/**
 * main - runs a simple shells
 * Return: 0 (success)
 */
int main(void)
{
	char *cmd = NULL, *args[1024];
	size_t n = 0;
	ssize_t len;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		len = getline(&cmd, &n, stdin);
		if (len == -1)
		{
			printf("\n");
			break;
		}

		cmd[len - 1] = '\0';
		exit_Builtin(cmd);
		env_Builtin(cmd);

		args_line(cmd, args);

		child_process(args);
	}

	free(cmd);
	return (0);
}

