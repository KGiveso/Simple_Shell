#include "shell.h"

/**
 * putchar - writes a character to stdout
 * @x: The character to print
 *
 * Return: 1 on success while -1 is returned
 * on error.
 */
int _putchar(char x)
{
	return (write(1, &x, 1));
}
