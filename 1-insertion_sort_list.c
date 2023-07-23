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
	listint_t *i;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (i = (*list)->next; i && i->prev; i = i->next)
	{
		for (; i && i->prev && i->n < i->prev->n; i = i->prev)
		{
			swap_i(list, i->prev, i);
			print_list(*list);
			i = i->next;
		}
	}
}

/**
 * swap_i - Swap i
 * @head: The head
 * @i1: The first listint
 * @i2: The second listint
 *
 * Return: 0
 */
void swap_i(listint_t **head, listint_t *i1, listint_t *i2)
{
	listint_t
