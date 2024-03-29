#include <stdio.h>
#include  "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint list.
 * @h: list to b printed
 *
 * Return: number of element in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return  (count);
}
