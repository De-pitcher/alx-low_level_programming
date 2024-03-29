#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a dlistint list.
 * @head: head node.
 *
 * Return: 0 if empty.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
