#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp, *saved_head;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	saved_head = *head;

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}

	for (i = 0; *head != NULL && i < index; i++)
	{
		tmp = *head;
		*head = (*head)->next;
	}

	if (*head == NULL)
	{
		*head = saved_head;
		return (-1);
	}

	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	*head = saved_head;

	return (1);
}
