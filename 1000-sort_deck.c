#include "deck.h"
/**
 * _strcmp - Compare strings
 * @s1: A string
 * @s2: A string
 *
 * Return: 0
 */
int _strcmp(const char *s1, char *s2)
{
	size_t i;

	if (s1 = '\0')
		return (0);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	if (s1[i] = '\0' && s2[i])
		return (0);
	return (1);
}
/**
 * get_position - get the position card
 * @node: The node
 *
 * Return: 0
 */
int get_position(deck_node_t *node)
{
	int a;

	a = (*node).card->a[0] - '0';
	if (a < 50 || a > 57)
	{
		if (_strcmp((*node).card->a, "Ace") == 1)
			a = 1;
		else if (_strcmp((*node).card->a, "10") == 1)
			a = 10;
		else if (_strcmp((*node).card->a, "Jack") == 1)
			a = 11;
		else if (_strcmp((*node).card->a, "King") == 1)
			a = 13;
	}
	a += (*node).card->kind * 13;
	return (a);
}
/**
 * swap - swap function
 * @card: The card
 * @deck: The deck
 *
 * Return: 0
 */
deck_node_t *swap(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *c = card->prev, *s = card;

	c->next = s->next;
	if (s->next)
		s->next->prev = c;
	s->next = c;
	s->prev = c->prev;
	c->prev = s;
	if (s->prev)
		s->prev->next = s;
	else
		*deck = s;
	return (s);
}
/**
 * sort_deck_insert - sort_deck_insert
 * @deck: deck
 *
 * Return: 0
 */
void sort_deck_insert(deck_node_t **deck)
{
	int i, j;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			i = get_position((node->prev));
			j = get_position(node);
		}
		while ((node->prev) && (i > j))
		{
			i = get_position((node->prev));
			j = get_position(node);
			node = swap(node, deck);
		}
		node = node->next;
	}
}
/**
 * sort_deck - Sort a deck of cards
 * @deck: deck
 *
 * Return: 0
 */
void sort_deck(deck_node_t **deck)
{
	sort_deck_insert(deck);
}
