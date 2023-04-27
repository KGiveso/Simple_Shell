#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* global variable */
extern char **environ;

/* function prototypes */
char **tokenize(char *cmd, char *delim, int *tokens);
char *_path(char *cmd);
char *_getenv(char *name);
void child_process(char **args);
void _free(char **args);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s1);
void exit_env(char *cmd);

#endif
