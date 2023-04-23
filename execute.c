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
		execve(args[0], args, NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
