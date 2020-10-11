#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Game.h"

void start(struct Deck *deck, struct Player *p, struct Player c[])
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

	int turn = 0; // turn

	// game(1) - give three card
	printf("\n□□□□□□□□□ Turn %d □□□□□□□□□\n", ++turn);
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
	checkRank(p);
	printf("==Computer 1 Card list==\n"); // Computer 1
	viewCard(&c[0]);
	printf("==Computer 2 Card list==\n"); // Computer 2
	viewCard(&c[1]);
	printf("==Computer 3 Card list==\n"); // Computer 3
	viewCard(&c[2]);

	printf("==Turn %d Betting!==\n", turn); // turn 1 Betting
	bettingPlayer(p);

	printf("\n□□□□□□□ Turn %d Finish □□□□□□□\n", turn);

	// game(2) - give one card
	printf("\n□□□□□□□□□ Turn %d □□□□□□□□□\n", ++turn);
	printf("Giving card...\n");
	getCard(p, deck);
	getCard(&c[0], deck);
	getCard(&c[1], deck);
	getCard(&c[2], deck);

	for (int i = 0; i < 3; i++)
	{
		openCard(&c[i], 3, 1);
	}

	printf("==Player Card list==\n"); // player
	viewCard(p);
	checkRank(p);
	printf("==Computer 1 Card list==\n"); // Computer 1
	viewCard(&c[0]);
	printf("==Computer 2 Card list==\n"); // Computer 2
	viewCard(&c[1]);
	printf("==Computer 3 Card list==\n"); // Computer 3
	viewCard(&c[2]);

	printf("==Turn %d Betting!==\n", turn); // turn 1 Betting
	bettingPlayer(p);

	printf("\n□□□□□□□ Turn %d Finish □□□□□□□\n", turn);

	// game(3) - give one card
	printf("\n□□□□□□□□□ Turn %d □□□□□□□□□\n", ++turn);
	printf("Giving card...\n");
	getCard(p, deck);
	getCard(&c[0], deck);
	getCard(&c[1], deck);
	getCard(&c[2], deck);

	for (int i = 0; i < 3; i++)
	{
		openCard(&c[i], 4, 1);
	}

	printf("==Player Card list==\n"); // player
	viewCard(p);
	checkRank(p);
	printf("==Computer 1 Card list==\n"); // Computer 1
	viewCard(&c[0]);
	printf("==Computer 2 Card list==\n"); // Computer 2
	viewCard(&c[1]);
	printf("==Computer 3 Card list==\n"); // Computer 3
	viewCard(&c[2]);

	printf("==Turn %d Betting!==\n", turn); // turn 1 Betting
	bettingPlayer(p);

	printf("\n□□□□□□□ Turn %d Finish □□□□□□□\n", turn);

	// game(4) - give one card
	printf("\n□□□□□□□□□ Turn %d □□□□□□□□□\n", ++turn);
	printf("Giving card...\n");
	getCard(p, deck);
	getCard(&c[0], deck);
	getCard(&c[1], deck);
	getCard(&c[2], deck);

	for (int i = 0; i < 3; i++)
	{
		openCard(&c[i], 5, 1);
	}

	printf("==Player Card list==\n"); // player
	viewCard(p);
	checkRank(p);
	printf("==Computer 1 Card list==\n"); // Computer 1
	viewCard(&c[0]);
	printf("==Computer 2 Card list==\n"); // Computer 2
	viewCard(&c[1]);
	printf("==Computer 3 Card list==\n"); // Computer 3
	viewCard(&c[2]);

	printf("==Turn %d Betting!==\n", turn); // turn 1 Betting
	bettingPlayer(p);

	printf("\n□□□□□□□ Turn %d Finish □□□□□□□\n", turn);


	// game(5) - give hidden card
	printf("\n□□□□□□□□□ Turn %d □□□□□□□□□\n", ++turn);
	printf("Giving card...\n");
	getCard(p, deck);
	getCard(&c[0], deck);
	getCard(&c[1], deck);
	getCard(&c[2], deck);

	// hidden -> no open

	printf("==Player Card list==\n"); // player
	viewCard(p);
	checkRank(p);
	printf("==Computer 1 Card list==\n"); // Computer 1
	viewCard(&c[0]);
	printf("==Computer 2 Card list==\n"); // Computer 2
	viewCard(&c[1]);
	printf("==Computer 3 Card list==\n"); // Computer 3
	viewCard(&c[2]);

	printf("==Turn %d Betting!==\n", turn); // turn 1 Betting
	bettingPlayer(p);

	printf("\n□□□□□□□ Turn %d Finish □□□□□□□\n", turn);

	// 이제 승패 결정

}