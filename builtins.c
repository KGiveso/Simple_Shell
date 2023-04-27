#include "shell.h"

/**
 * exit_env - handles exit and env built-ins
 * @cmd: exit command or env variable entered
 */
void exit_env(char *cmd)
{
	char **env;

	if (_strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(cmd, "env") == 0 || _strcmp(cmd, "printenv") == 0)
	{
		env = environ;
		while (*env)
		{
			write(2, *env, _strlen(*env));
			write(2, "\n", strlen("\n"));
			env++;
		}
	}
}
