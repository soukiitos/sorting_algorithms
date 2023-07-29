#include "deck.h"
/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
/**
 * get_card_value - Get the value of a card
 * @card: A pointer
 *
 * Return: 0
 */
char get_card_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	return (13);
}
/**
 * sort_deck - Sort a deck of cards
 * @deck: deck
 *
 * Return: 0
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *i, *j, *tmp;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	for (i = (*deck)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		j = i->prev;
		while (j != NULL &&
				(j->card->kind > i->card->kind ||
				 (j->card->kind == i->card->kind &&
				  get_card_value(j) > get_card_value(i))
				)
		      )
		{
			j->next = i->next;
			if (i->next != NULL)
				i->next->prev = j;
			i->prev = j->prev;
			i->next = j;
			if (j->prev != NULL)
				j->prev->next = i;
			else
				*deck = i;
			j->prev = i;
			j = i->prev;
		}
	}
}
