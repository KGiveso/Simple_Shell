#include "shell.h"
/**
 * main - Entry point for the simple shell project created
 * C language ending task.
 * Return: (0) on success
 */
int main(void)
{
	ssize_t bytes_rd = 0;
	size_t bf_size = 0;
	char *in = NULL, *strings[20];
	int count = 1, vf_stat = 0, exist_stat = 0, exit_stat = 0, blt_stat = 0;

	_fprint("$ ", 2);
	bytes_rd = getline(&in, &bf_size, stdin);
	while (bytes_rd != -1)
	{
		if (*in != '\n')
		{
			_inputs(in, strings);
			if (strings[0] != NULL)
			{
				exist_stat = _file(strings[0]);
				if (exist_stat != 0)
				{
					vf_stat = _path(strings);
					if (vf_stat == 0)
						exit_stat = _execute(strings), free(in), free(*strings);
					else
					{
					blt_stat = _builtin(strings, exit_stat);
					if (blt_stat != 0)
						exit_stat = _error(strings, count), free(in);
					}
				}
				else
					exit_stat = _execute(strings), free(in);
			}
			else
				free(in);
		}
		else if (*in == '\n')
			free(in);
		in = NULL, count++;
		_fprint("$ ", 2), bytes_rd = getline(&in, &bf_size, stdin);
	}
	_freed(in);
	return (exit_stat);
}
