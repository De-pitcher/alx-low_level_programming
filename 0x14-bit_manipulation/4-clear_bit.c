#include "main.h"

/**
 * clear_bit - sets the value of a bit to at a given index.
 * @n: pointer to an unsigned long int.
 * @index: index of the bit
 *
 * Return: On success 1, On error -1.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m;

	if (index > 63)
		return (-1);

	m = 1 << index;

	if (*n & m)
		*n ^= m;

	return (1);
}
