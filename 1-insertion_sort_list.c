#include "sort.h"
/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The list
 *
 * Return: 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			if (j->prev != NULL)
				j->prev->next = i;
			else
				*list = i;
			if (i->next != NULL)
				i->next->prev = j;
			i->prev = j->prev;
			j->prev = i;
			j->next = i->next;
			i->next = j;
			print_list((const listint_t *)*list);
			j = i->prev;
		}
	}
}
