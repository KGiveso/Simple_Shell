#include "shell.h"

/**
 * child_process - creates a new process to execute the command
 * @args: array of pointers to command line
 */
void child_process(char *args[100])
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror(args[0]);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror(args[0]);
		exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}
