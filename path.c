#include "shell.h"

char *_getenv(char *name)
{
	char *value, **var;
	int i = 0, tokens = 0, len;

	if (name == NULL)
		return (NULL);

	while (__environ[i])
	{
		var = tokenize(__environ[i], "=", &tokens);
		if (_strcmp(name, var[0]) == 0)
		{
			if (var[1] == NULL)
			{
				value = malloc(sizeof(char) * (1));
				if (value == NULL)
					return (NULL);
				value[0] = '\0';
				return (value);
			}
			len = _strlen(var[1]);
			value = malloc(sizeof(char) * (len + 1));
			if (value == NULL)
				return (NULL);
			_strcpy(value, var[1]);
			value[len] = '\0';
			return (value);
		}
		i++;
	}
	return (NULL);
}

char *_path(char *cmd)
{
	char *path, **dir, *full_path;
	int i = 0, len, max_num = 0;

	path = _getenv("PATH");

	dir = malloc(sizeof(char*) * 1024);
	if (dir == NULL)
		return (NULL);

	dir = tokenize(path, ":", &max_num);

	while (i < max_num)
	{
		len = _strlen(dir[i]);
		full_path = malloc(len + _strlen(cmd) + 2);
		_strcpy(full_path, dir[i]);
		full_path[len] = '/';
		_strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
			return (full_path);
		i++;
	}
	_free(dir);
	return (full_path);
}
