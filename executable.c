#include "shell.h"
/**
 * _execute - Buildup a new child process, execute to update the status
 * @strings:input an array
 * Return: 0 if success
 */
int _execute(char **strings)
{
	pid_t pid = 0;
	int stat = 0, ex_stat = 0;

	pid = fork();
	if (pid == -1)
		_fprint("failed\n", 7);
	else if (pid == 0)
	{
		ex_stat = execve(strings[0], strings, environ);


		if (ex_stat == -1)
		{
			ex_stat = 126;
			perror("hsh");
			exit(ex_stat);
		}
		exit(0);
	}
	else
		wait(&stat);
	ex_stat = WEXITSTATUS(stat);
	return (ex_stat);
}
