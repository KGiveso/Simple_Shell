#include "shell.h"
/**
* get_static - implements a buffer to read many chars at once
* Return: NULL if end of file is reached
*/
char *get_static(void)
{
static char buffer[1024];
static int pos;
static int size;
char *line = NULL;
int i = 0, j;

while (1)
{
if (pos == size)
{
size = read(STDIN_FILENO, buffer, sizeof(buffer));
pos = 0;

if (size == 0)
{
break;
}
}
if (buffer[pos] == '\n')
{
line = (char *) malloc(i + 1);
if (line == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
for (j = 0; j < i; j++)
{
line[j] = buffer[j];
}
line[i] = '\0';
pos++;
break;
}
i++;
pos++;
}
return (line);
}
/**
* main-prints a line
* return: 0
*/
int main(void)
{
printf("line ");
return (0);
}
