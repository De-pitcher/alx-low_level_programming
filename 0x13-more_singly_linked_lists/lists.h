#ifndef LISTS_H
#define LISTS_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked node structure
 * for Holberton project
 */

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/**
 * struct list_addr_s - singly linked list
 * @addr: pointer address value
 * @next: points to the next node
 *
 * Description: singly linked node structure
 * for Holberton project
 */

typedef struct list_addr_s
{
    size_t addr;
    struct list_addr_s *next;
} list_addr;

size_t print_listint(const listint_t *h);

#endif
