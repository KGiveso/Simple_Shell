#include "shell.h"

/**
 * exit_Builtin - implements the exit built-in to exit shell
 * @cmd: pointer to the exit command entered by user
 */
void exit_Builtin(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
}

/**
 * env_Builtin - implements the env built-in
 * and prints the current environment
 * @cmd: env or printenv variable as input
 */
void env_Builtin(char *cmd)
{
	char **env;

	if (strcmp(cmd, "env") == 0 || strcmp(cmd, "printenv") == 0)
	{
		env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
