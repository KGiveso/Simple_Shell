#include "shell.h"

/**
 * main - runs a simple shells
 * Return: 0 (success)
 */
int main(void)
{
	char *cmd = NULL, *args[256];
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
		if (strcmp(cmd, "exit") == 0)
		{
			exit_Builtin(cmd);
		}
		else if (strcmp(cmd, "env") == 0 || strcmp(cmd, "printenv") == 0)
		{
			env_Builtin();
			continue;
		}

		args_line(cmd, args);

		child_process(args);
	}

	free(cmd);
	return (0);
}
