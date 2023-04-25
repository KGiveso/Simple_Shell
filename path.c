#include "shell.h"
/**
 * _path - Concatenates an input with paths in global variable PATH
 * @cmd: directory string to be append with the command
 * @command: command to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *_path(char *cmd, char *command)
{
	int a, b = 0, len1, len2;
	char *command_path = NULL;

	if (cmd == NULL || command == NULL)
		return (NULL);

	len1 = strlen(cmd);
	len2 = strlen(command);
	command_path = malloc(len1 + len2 + 2);
	if (command_path == NULL)
		return (NULL);
	for (a = 0; cmd[a] != '\0'; a++)
	{
		command_path[a] = cmd[a];
	}
	if (cmd[a - 1] != '/')
	{
		command_path[a] = '/';
		a++;
	}
	while (command[b] != '\0')
	{
		command_path[a + b] = command[b];
		b++;
	}
	command_path[a + b] = '\0';
	return (command_path);
}
