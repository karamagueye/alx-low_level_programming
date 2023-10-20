#include <stdlib.h>
#include "lists.h"

/**
 *  list_len - adds a new node at the beginning of a list_t
 *  @h: pointer to the list_t list
 *  Return: the address of the new element, or NULL if it failed
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);


}
