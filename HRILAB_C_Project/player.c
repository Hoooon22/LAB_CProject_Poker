#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

#include "Player.h"

// Player
void initPlayer(struct Player *p)
{
	p->money = 1000;
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
	for (int i = 0; a->card[i].shape != NULL; i++)
	{
		printf("Card [%d] : %s %d\n", i + 1, a->card[i].shape, a->card[i].number);
	}
	printf("-------------------------\n\n");
}