#include "shell.h"
/**
 * _path - Evaluates if the first argument is a command
 * whose path can be executed.
 * @strings: array of entries by the user
 *
 * Return: (0) if success, or -1 if the exe file don't exist
 */
int _path(char **strings)
{
	char *local_path = NULL;
	char *local_dup = NULL;
	char *dir_path = NULL;
	char *command_path = NULL;
	char *test_cph[121];
	int exist_stat = -1, i = 0;

	local_path = _env("PATH");
	if (local_path == NULL)
		return (-1);
	local_dup = (_strdup(local_path));
	dir_path = strtok(local_dup, ":");
	if (dir_path == NULL)
		return (-1);
	free(local_path);
	while (exist_stat == -1 && dir_path != NULL)
	{
		command_path = append_command(dir_path, strings[0]);
		test_cph[i] = command_path;
		exist_stat = _file(test_cph[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(local_dup);
	_grid(test_cph, i);
	if (exist_stat == 0)
	{
		strings[0] = test_cph[i];
		return (0);
	}
	else
	{
		free(test_cph[i]);
		return (-1);
	}
}
