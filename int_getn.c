#include <string.h>
#include "header.h"
/**
* _getn - compares the string to environmental token returns the location.
* @name: string name passing through
* Return: return the location number.
**/

int _getn(char *name)
{

	int x = 0;
	int len = _strlen(name);

	for (x = 0; environ[x]; x++)
	{

		if (_strncmp(environ[x], name, len) == 0)
		{

			return (x);
		}


	}


	return (-1);

}
