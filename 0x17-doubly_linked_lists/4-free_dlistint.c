#include <stdio.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @jhead: head node.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (!head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
