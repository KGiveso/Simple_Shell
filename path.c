#include "shell.h"
/**
 * append_command - Concatenates an input with paths in global variable PATH
 * @dir_path: directory string to be append with the command
 * @instruct: command to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *append_command(char *dir_path, char *instruct)
{
	int a, b = 0, len1, len2;
	char *command_path = NULL;

	if (dir_path == NULL || instruct == NULL)
		return (NULL);

	len1 = _strlen(dir_path);
	len2 = _strlen(instruct);
	command_path = malloc(len1 + len2 + 2);
	if (command_path == NULL)
		return (NULL);
	for (a = 0; dir_path[a] != '\0'; a++)
	{
		command_path[a] = dir_path[a];
	}
	if (instruct[a - 1] != '/')
	{
		command_path[a] = '/';
		a++;
	}
	while (instruct[b] != '\0')
	{
		command_path[a + b] = instruct[b];
		b++;
	}
	command_path[a + b] = '\0';
	return (command_path);
}
