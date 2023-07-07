#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary number as string
 *
 * Return: converted number or 0 if there is an error.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int ui = 0, b_two = 1;
	int len;

	if (!b)
		return (0);

	for (len = 0; b[len] != '\0'; len++)
		;

	for (len--, b_two = 1; len >= 0; len--, b_two *= 2)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		if (b[len] & 1)
			ui += b_two;
	}

	return (ui);
}
