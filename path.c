#include "shell.h"
/**
* handle_path - Concatenates an input with paths in global variable PATH
* @dire_path: concatenates as the directory string with the command.
* @command: command to be concatenated with the directory
* Return: Buffer to concatenated path
*/
char *handle_path(char *dire_path, char *command)
{
int a, b = 0, len1, len2;
char *command_path = NULL;

if (dire_path == NULL || command == NULL)
return (NULL);

len1 = strlen(dire_path);
len2 = strlen(command);
command_path = malloc(len1 + len2 + 2);
if (command_path == NULL)
return (NULL);
for (a = 0; dire_path[a] != '\0'; a++)
{
command_path[a] = dire_path[a];
}
if (dire_path[a - 1] != '/')
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

