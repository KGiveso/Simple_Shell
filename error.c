#include "shell.h"
/**
 * _error - Prints error message when a command is not found
 * @strings: array of args typed by the user
 * @count: Times that the shell has been executed
 * Return: Exit status
 */
int _error(char **strings, int count)
{
	char *interactive_mode = "hsh";
	char *non_intr_mode = "hsh";

	if (isatty(STDIN_FILENO))
		write(2, interactive_mode, 3);
	else
	{
		write(2, non_intr_mode, 5);
	}
	write(2, ": ", 2);
	stat_error(count);
	write(2, ": ", 2);
	write(2, strings[0], _strlen(strings[0]));
	write(2, ": not found\n", 12);
	return (127);
}
