#include "header.h"
#include <stdlib.h>

/**
 * free_list - frees a listint list
 * @head: listint_t
 * Return: void
 */


void free_list(list **head)
{

	list *new;

	if (!head)
		return;

	while ((*head) != NULL)
	{
		new = *head;
		(*head) = (*head)->next;
		free(new->s);
		free(new);

	}

	(*head) = NULL;


}
