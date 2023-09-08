#include "hash_tables.h"

int add_collision_node(hash_table_t *ht, unsigned long int index,
		const char *key, const char *value);

/**
 * add_collision_node - Add a collision node to the hash table
 * @ht: The hash table
 * @index: The index where the collision occurs
 * @key: The key to add
 * @value: The value to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */
int add_collision_node(hash_table_t *ht, unsigned long int index,
		const char *key, const char *value)
{
	hash_node_t *new_node, *current, *prev;

	current = ht->array[index];
	prev = NULL;

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		prev = current;
		current = current->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = NULL;
	if (prev == NULL)
		ht->array[index] = new_node;
	else
		prev->next = new_node;

	return (1);
}


/**
 * hash_table_set - Add a key-value pair to the hash table
 * @ht: The hash table
 * @key: The key to add
 * @value: The value to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	return (add_collision_node(ht, index, key, value));
}
