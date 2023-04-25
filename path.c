#include "shell.h"

/**
 * _path - handles the PATH
 * @cmd: command read from input
 * Description: fork must not be called if the command doesn’t exist
 * Return:
 */

char *_path(char *cmd)
{
	char *path, *full_path, *token;
	size_t path_len, cmd_len;
	struct strcat st = {0};

	path = getenv("PATH");
	if (path)
	{
		cmd_len = strlen(cmd);

		token = strtok(path, ":");
		while (token != NULL)
		{
			path_len = strlen(token);
			full_path = malloc(cmd_len + path_len + 2);
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, cmd);

			if (strcat(full_path, &st) == 0)
			{
				return (full_path);
			}
			else
			{
				free(full_path);
				token = strtok(NULL, ":");

			}
		}

		if (strcat(cmd, &st) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	else
	{
		return (NULL);
	}
}


/**
 * child_process - creates a new process to execute the commands
 * @args: the array of pointers to arguments to execute
 */
void child_process(char *args[])
{
	int status;
	pid_t pid;

	pid = fork();

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
