#include "sort.h"
/**
 * swap - Swap nodes
 * @list: A pointer
 * @n1: The first node
 * @n2: The second node
 *
 * Return: 0
 */
void swap(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;
	if (n2->next != NULL)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * cocktail_sort_list - Sort a doubly linked list of integers
 * @list: The list
 *
 * Return: 0
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *i, *j;
	int not_stir = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (i = *list; i->next != NULL;)
		i = i->next;
	while (not_stir == 0)
	{
		not_stir = 1;
		for (j = *list; j != i; j = j->next)
		{
			if (j->n > j->next->n)
			{
				swap(list, j, j->next);
				print_list((const listint_t *)*list);
				not_stir = 0;
			}
		}
		i = i->prev;
		if (not_stir)
			break;
		not_stir = 1;
		for (j = j->prev; j != *list; j = j->prev)
		{
			if (j->n < j->prev->n)
			{
				swap(list, j->prev, j);
				print_list((const listint_t *)*list);
				not_stir = 0;
			}
		}
	}
}
