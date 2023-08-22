#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node oa dlistint_t list.
 * @head: head node.
 * @index: index to be returned.
 *
 * Return: nth node.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	return (current);
}
