#include "header.h"
#include <stdlib.h>

/**
 * add_node - add node at the end
 * @head: listint_t **
 * @str: const int
 * Return: listint_t
 */

list *add_node(list **head, char *str)
{
	list *temp = *head;
	list *place = *head;
	list *new = malloc(sizeof(list));

	if (!new)
		return (NULL);

	new->s = _strdup(str);
	new->next = NULL;


	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;

	return (place);



}

