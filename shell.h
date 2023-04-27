#ifndef SHELL_H
#define SHELL_H

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

/*Extension Functions*/
extern char **environ;

/*Function Prototypes*/
int _strcmp(char *cmd, char *argv);
int _path(char **strings);
int _builtin(char **strings, int exit_stat);
char *_env(char *local_var);
char *_strdup(char *std);
char *append_command(char *dir_path, char *instruct);
int _fprint(const char *prompt, unsigned int sizes);
void _freed(char *in);
int _inputs(char *in, char **strings);
int stat_error(int n);
int _error(char **strings, int count);
int _putchar(char c);
int _file(char *pathfile);
int _execute(char **strings);
void _grid(char **grid, int altitude);
int _strlen(const char *std);


#endif
