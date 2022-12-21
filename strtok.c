#include "header.h"
/**
 * _strtok - takes the string and deliminates all the charactors specified.
 * @str: string being check.
 * @delim: deliminator being ommitte.
 * Return: string with a null byte at the end.
 **/
char *_strtok(char *str, char *delim)
{

	static char *s;
	int len = _strlen(delim);
	int i = 0;

	if (str)
		s = str;

	else
	{
		str = s;
		s = str;
	}

	if (*s == '\0')
		return (NULL);

	while (*s != '\0')
	{
		if (_strncmp(str, delim, len) == 0)
		{
			str++;
		}
		else if (_strncmp(s, delim, len) == 0)
		{
			for (i = 0; i < len; i++, s++)
			{
				*s = '\0';
			}
				return (str);

		}

		s++;
	}

	return (str);

}
/**
 * _strn - string count while checking for deliminators.
 * @str: string that is being ran.
 * Return: count of from the string.
 **/
int _strn(char *str)
{
	int count = 0;

	if (!str)
		return (-1);

	while (*str)
	{
		if (*str != ' ' && *str != '\n' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
		{
			count++;
		}
		str++;
	}

	return (count);

}
