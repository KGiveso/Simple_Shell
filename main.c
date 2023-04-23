#include "shell.h"
char *handle_path(char *dire_path, char *command);
void child_process(char *args[]);
/**
* main - runs a simple shells
* Return: 0 (success)
*/
int main(void)
{
char *cmd = NULL, *args[100];
size_t n = 0;
ssize_t len;
while (1)
{
printf("$ ");
fflush(stdout);

len = getline(&cmd, &n, stdin);
if (len == -1)
{
printf("\n");
break;
}

cmd[len - 1] = '\0';

args_line(cmd, args);

child_process(args);
}

free(cmd);
return (0);
}

/**
* child_process - creates a new process to execute the commands
* @args: the array of pointers to arguments to execute
*/
void child_process(char *args[])
{
int status;
pid_t pid = fork();

if (pid == -1)
{
perror("Error");
exit(0);
}
else if (pid == 0)
{
char *path = handle_path(getenv("PATH"), args[0]);
if (path == NULL)
{
printf("%s: command not found\n", args[0]);
exit(0);
}
execve(path, args, NULL);
perror("Error");
exit(0);
}
else
{
wait(&status);
}
}
/**
* handle_path - looks for a command in the directories of the PATH
* @dire_path: the string containing the PATH
* @command: the command to look for
* Return: the path to the command if found, NULL otherwise
*/
char *handle_path(char *dire_path, char *command)
{
char *path = strtok(dire_path, ":");

while (path != NULL)
{
char *full_path = malloc(strlen(path) + strlen(command) + 2);
sprintf(full_path, "%s/%s", path, command);
if (access(full_path, F_OK | X_OK) != -1)
return (full_path);
free(full_path);
path = strtok(NULL, ":");
}
return (NULL);
}

