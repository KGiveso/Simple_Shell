#include "shell.h"
/**
 * _fprint - prints the prompt in the standard input
 * @sizes: input lenght of string
 * @prompt: input Pointer to the string to be printed
 * Return: 0 if success or -1 if fails
 */
int _fprint(const char *prompt, unsigned int sizes)
{
	int insert = 0;

	if (isatty(STDIN_FILENO))
	{
		insert = write(1, prompt, sizes);
		if (insert == -1)
			return (-1);
	}
		return (0);
}
