#include "header.h"
#include <stdlib.h>
/**
 * delete_node - deletes the node of a list array.
 * @head: double pointer.
 * @index: unsigned int of the index.
 *
 * Return: is void.
 **/

void delete_node(list **head, unsigned int index)
{
	list *new = *head;
	list *temp;
	unsigned int counter = 0;

	if (!head)
		return;

	if (index == 0)
	{
		*head = (*head)->next;
		free(new->s);
		free(new);
		return;
	}
	while (new)
	{
		if (index == counter + 1)
		{
			temp = new->next;
			new->next = new->next->next;
			free(temp->s);
			free(temp);
			return;
		}
		counter++;
		new = new->next;
	}

}
