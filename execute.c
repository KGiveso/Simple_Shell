#include "shell.h"

/**
 * child_process - creates a new process to execute the command
 * @args: array of pointers to command line
 */
void child_process(char **args)
{
	char *full_path = malloc(sizeof(char) * 1024);

	if (full_path == NULL)
		exit(EXIT_FAILURE);

	pid_t pid = fork();

	if (pid == -1)
	{
		perror(args[0]);
	}
	else if (pid == 0)
	{
		full_path = _path(args[0]);

		if (args[0][0] == '/' || full_path == NULL)
			full_path = _strdup(args[0]);

		if (execve(full_path, args, NULL) == -1)
			perror(args[0]);

		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);

	free(full_path);
}
