#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "header.h"
#include <string.h>
#include <signal.h>
/**
 * is_a - is a / then it returns -1 and pushes the string forward.
 * @s: string position
 * Return: 1 if (SUCCESS)
 **/

int is_a(char *s)
{

	while (*s)
	{
		if (*s == '/')
			return (-1);
		s++;
	}

	return (1);
}
