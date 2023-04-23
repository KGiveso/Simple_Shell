#include "shell.h"
/**
* _strdup - split a string
* @strt: string to be splitted
* Return: Pointer to the split string
*/
char *_strdup(char *strt)
{
unsigned int i, len;
char *split;
if (strt == NULL)
return (NULL);
for (len = 0; strt[len] != '\0'; len++)
;
split = (char *) malloc(sizeof(char) * (len + 1));
if (split == NULL)
return (NULL);
for (i = 0; i <= len; i++)
{
split[i] = strt[i];
}
return (split);
}
/**
*main
*return:0
*/
int main(void)
{
char *input = "strt";
char *split = _strdup(input);
printf("%s\n", split);
free(split);
return (0);
}
