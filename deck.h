#ifndef DECK_H
#define DECK_H
#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - The kind_e card
 * @SPADE: The spade kind
 * @HEART: The heart kind
 * @CLUB: The club kind
 * @DIAMOND: The diamond kind
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int _strcmp(const char *s1, const char *s2);
char get_card_value(deck_node_t *card);
#endif
