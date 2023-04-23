#include "shell.h"

/**
 * exit_Builtin - implements the exit built-in to exit shell
 * @cmd: pointer to the exit command entered by user
 */
void exit_Builtin(char *cmd)
{
	free(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * env_Builtin - implements the env built-in
 * and prints the current environment
 */
void env_Builtin(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
