#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* environ variable */
extern char **environ;

/* Function Prototypes */
void child_process(char *args[]);
void exit_Builtin(char *cmd);
void env_Builtin(void);
int main(void);
int args_line(char *entry, char **arguments);
char *handle_path(char *dire_path, char *command);

#endif

