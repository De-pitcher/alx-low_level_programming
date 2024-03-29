#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to an unsigned long int
 * @index: index of the bit
 *
 * Return: On success, -1 on error.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > 63)
		return (-1);

	mask = 1 << index;
	*n = (*n | mask);

	return (1);
}
