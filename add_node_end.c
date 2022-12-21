#include "header.h"
#include <stdlib.h>
/**
 * add_node_end - adds the node to the end.
 * @head: double pointer of the head list.
 * @str: char string.
 * Return: addnode of the list to the end.
 **/
list *add_node_end(list **head, char *str)
{
	list *temp = *head;
	list *place = *head;
	list *new = malloc(sizeof(list));

	if (!new)
		return (NULL);

	new->s = _strdup(str);

	if (!*head)
	{
		*head = new;
		return (new);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;

	return (place);
}
