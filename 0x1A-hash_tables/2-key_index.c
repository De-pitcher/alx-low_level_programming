#include "hash_tables.h"

/**
 * key_index - Get the index at which a key should be stored in a hash table
 * @key: The key to calculate the index for
 * @size: The size of the hash table's array
 *
 * Return: The index at which the key should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	if (key == NULL || size == 0)
		return (0);

	hash_value = hash_djb2(key);
	return (hash_value % size);
}
