#include "shell.h"
/**
 * _env - Content of a global variable
 * @local_var: input variable to extract from environment
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *_env(char *local_var)
{
	int j = 0;
	const char cutter[] = "=";
	char *env1, *env2, *env3;

	if (local_var != NULL)
	{
		if (environ == NULL)
			return (NULL);
		env2 = _strdup(environ[j]);
		while (env2 != NULL)
		{
			env1 = strtok(env2, cutter);
			if (_strcmp(env1, local_var) == 0)
			{
				env1 = strtok(NULL, cutter);

				env3 = _strdup(env1);
				free(env2);
				return (env3);
			}
			j++;
			free(env2);
			env2 = _strdup(environ[j]);
		}
	}
	return (NULL);
}
