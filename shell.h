#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/* Function Prototypes */
/**Task 0 and 1**/
void child_process(char *args[]);
int main(void);

/**Task 2 and 3 */
int args_line(char *entry, char **arguments);
char *handle_path(char *dire_path, char *command);

/**Task 4 and 5*/
void exit_Builtin(char *cmd);
void child_process(char *args[]);

/**Task 6 and 7*/
char *get_static(void);
char *_strdup(char *strt);

#endif /*SHELL_H*/
