#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Game.h"

void start(struct Deck *deck, struct Player *p, struct Computer *c)
{
	initDeck(deck);

	printf("Let's start Poker game!!\n");
	// init
	initPlayer(p);
	for (int i = 0; i < 3; i++)
	{
		initComputer(&c[i]);
	}
	printf("Init complete!\n\n");

	// Bet
	bettingPlayer(p);
	for (int i = 0; i < 3; i++)
	{
		bettingComputer(&c[i]);
	}

	// game(1) - give four card
	
}