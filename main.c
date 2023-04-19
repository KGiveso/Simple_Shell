#include "shell.h"

int child_process(char *args[]);

/**
 * main - runs a simple shells
 * Return: 0 (success)
 */
int main(void)
{
	char *cmd = NULL, *args[100];
	size_t n = 0;
	int status, i;
	ssize_t len;

	while (1)
	{
		printf("> ");
		fflush(stdout);

		len = getline(&cmd, &n, stdin);
		if (len == -1)
		{
			printf("\n");
			break;
		}

		cmd[len - 1] = '\0';

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

/**
 * child_process - creates a new process to execute the commands
 * @args: the array of pointers to arguments to execute
 *
 * Return: 1 (fail)
 */
int child_process(char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error");
		return (1);
	}
	else
	{
		wait(NULL);
	}
}
