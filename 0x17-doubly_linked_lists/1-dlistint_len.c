#include "lists.h"

/**
 * Description: dlistint_len - return the number of elements
 * in a linked dlistint_t list.
 * @h: head of the file
 * Return: the number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	int count;

	count = 0;
	if (h == NULL)
		return (count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		count++;
	        h = h->next;
	}

		return (count);
}
