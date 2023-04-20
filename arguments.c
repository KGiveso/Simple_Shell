#include "shell.h"
/**
* args_line - Write an array with every input listed by user
* @entry: String with the input
* @arguments: Array to be filled
* Return: Length of the array
*/
int args_line(char *entry, char **arguments)
{
int i = 0;
char *options, *aux = entry, *command;
command = strtok(entry, "\n\t\r ");
arguments[i] = command;
while (aux != NULL)
{
++i;
options = strtok(NULL, "\n\t\r ");
aux = options;
arguments[i] = options;
}
arguments[i] = NULL;
return (i);
}
