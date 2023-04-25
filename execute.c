#include "shell.h"

/**
 * child_process - creates a new process to execute the commands
 * @args: the array of pointers to arguments to execute
 */
void child_process(char *args[])
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *cmd, *full_path;

		cmd = args[0];
		full_path = malloc(1024);

		full_path = _path(cmd);

		execve(full_path, args, NULL);
		perror("Error");

		free(full_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
