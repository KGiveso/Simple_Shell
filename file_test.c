#include "shell.h"
/**
 * _file - checks existence of file
 * @pathfile: input path to the file
 * Return: 0 if the file exist or -1 if not
 */
int _file(char *pathfile)
{
	int exist_status;

	exist_status = (open(pathfile, O_RDONLY));
	if (exist_status != -1)
	{
		close(exist_status);
		return (0);
	}
	else
		return (-1);
}
