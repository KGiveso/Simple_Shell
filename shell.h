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
/**Task 0 and 1**/
void child_process(char *args[]);
void exit_Builtin(char *cmd);
void env_Builtin(char *cmd);
int main(void);

/**Task 2 and 3 */
int args_line(char *entry, char **arguments);
char *_path(char *cmd);

/**Task 4 and 5*/
void exit_Builtin(char *cmd);
void child_process(char *args[]);


#endif /*SHELL_H*/
