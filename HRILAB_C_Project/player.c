#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

#include "Player.h"

// Player
void initPlayer(struct Player *p)
{
	p->money = 1000;
	for (int i = 0; i < 7; i++)
	{
		p->open[i] = 1; // open
	}
	p->count = 0;
}

void bettingPlayer(struct Player *p)
{
	printf("Player Betting...\n");
	int num;
	printf("Input betting money (current money : %d) : ", p->money);
	scanf("%d", &num);
	while (num > p->money)
	{
		printf("Over money! Try again. : ");
		scanf("%d", &num);
	}
	p->bet_m = num;
	printf("done.\n");
}

/* ---------------------------------------------------- */
// Computer

void initComputer(struct Player *c)
{
	c->money = 1000; // $1000
	for (int i = 0; i < 7; i++)
	{
		c->open[i] = 0; // close
	}
	c->count = 0;
}

void bettingComputer(struct Player *c)
{
	srand((unsigned int)time(NULL));
	c->bet_m = 10 + (10 * rand() % (10)); // 10 ~ 100
	printf("Computer betting complete.\n");
}

/* ---------------------------------------------------- */
// all
void viewCard(struct Player *a)
{
	printf("\n-------------------------\n");
	for (int i = 0; i < a->count; i++)
	{
		if (a->open[i] == 0)
			printf("Card [%d] : Blined\n", i + 1);
		else
			printf("Card [%d] : %s %d\n", i + 1, a->card[i].shape, a->card[i].number);
	}
	printf("-------------------------\n\n");
}

void getCard(struct Player *a, struct Deck *deck)
{
	static struct Card tmp_card;
	tmp_card = giveCard(deck);
	a->card[a->count].shape = tmp_card.shape;
	a->card[a->count].number = tmp_card.number;
	a->count++;
}

void openCard(struct Player *a, int num, int open_n)
{
	a->open[num] = open_n;
}