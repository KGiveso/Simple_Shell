#include "shell.h"

/**
 * _strlen - returns length of a string
 * @str: string literal
 * Return: length of string
 */
int _strlen(char *str)
{
	int len;

	len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}

	return (len);
}

/**
 * _strcpy - copies a string
 * @src: string literal to copy
 * @dest: pointer that needs populating with copy
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *tmp;

	tmp = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	dest++;
	dest = tmp;
	return (dest);
}

/**
 * _strcat - concatenates a string to another string
 * @src: string to append
 * @dest: string to appended to
 * Return: pointer to a char string
 */
char *_strcat(char *dest, char *src)
{
	int i, len = 0;

	for (i = 0; dest[i]; i++)
	{
		len++;
	}

	for (i = 0; src[i]; i++)
	{
		dest[len++] = src[i];
	}

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: integer value
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strdup - duplicates a string
 * @s1: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *s1)
{
	char *s2;
	int i = 0, j = 0;

	if (s1 == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		i++;
	}

	s2 = malloc(sizeof(char) * i + 1);
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[i] = s1[i];

	return (s2);
}

