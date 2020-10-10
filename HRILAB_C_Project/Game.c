#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Game.h"

void start(struct Deck *deck, struct Player *p, struct Player *c[])
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

	int turn = 1; // turn
	// game(1) - give three card

	printf("\n-------------Turn 1-------------\n");
	printf("Giving card...\n");

	for (int i = 0; i < 3; i++)
	{
		getCard(p, deck);
		getCard(&c[0], deck);
		getCard(&c[1], deck);
		getCard(&c[2], deck);
	}
	for (int i = 0; i < 3; i++)
	{
		openCard(&c[i], 2, 1);
	}
	printf("==Player Card list==\n"); // player
	viewCard(p);
	printf("==Computer 1 Card list==\n"); // Computer 1
	viewCard(&c[0]);
	printf("==Computer 2 Card list==\n"); // Computer 2
	viewCard(&c[1]);
	printf("==Computer 3 Card list==\n"); // Computer 3
	viewCard(&c[2]);

}