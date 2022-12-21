#include "header.h"
#include <string.h>
#include <stdlib.h>

list *getpath(void)
{

	char *path = _getenv("PATH");

	char *copy = _strdup(path);

	int index = pathchecker(copy);

	int icomp = 0;

	char *token = _strtok(copy, ":");

	list *head;

	head = NULL;

	while (token)
	{
		if (index == icomp)
			add_node(&head, "./");

		add_node(&head, token);
		token = _strtok(NULL, ":");

		icomp++;
	}
	if (index == icomp)
		add_node(&head, "./");


	free(copy);
	free(path);
	return (head);
}
/**
 * pathchecker - chec the path of the copyt string.
 * @copy: copied string being checked.
 * Return: the string to index else -1 if it fails.
 **/


int pathchecker(char *copy)
{

	char *temp = copy;
	int index = 0;

	if (*temp == ':')
		return (0);

	while (*temp)
	{
		if (*temp == ':')
		{
			index++;

			if (*(temp + 1) == ':' || *(temp + 1) == '\0')
				return (index);


		}

		temp++;

	}

	return (-1);
}


list *genv(void)
{


	list *head;

	head = NULL;

	while (*environ)
	{
		add_node(&head, *environ);
		environ++;
	}

return (head);

}
