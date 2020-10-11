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
	p->rank[0] = -1;
	p->rank[1] = -1;
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
	p->money -= num;
	p->bet_m += num;
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
	c->rank[0] = -1;
	c->rank[1] = -1;
}

void bettingComputer(struct Player *c)
{
	srand((unsigned int)time(NULL));
	c->bet_m = 10 + (10 * rand() % (10)); // 10 ~ 100
	c->money -= c->bet_m;
	printf("Computer betting complete.\n");
}

/* ---------------------------------------------------- */
// all
void viewCard(struct Player *a)
{
	printf("-------------------------\n");
	for (int i = 0; i < a->count; i++)
	{
		if (a->open[i] == 0)
			printf("Card [%d] : Blined\n", i + 1);
		else
			printf("Card [%d] : %s %d\n", i + 1, a->card[i].shape, a->card[i].number);
	}
	printf("-------------------------\n");
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

void checkRank(struct Player *a)
{
	// check Ranks of Hands -> (0, pair), (1, two Pair), (2, triple), (3, straight), (4, flush), (5, full house), (6, fourCard)
	int pair[2] = { 0,0 }; // [0] = times, [1] = level
	int triple[2] = { 0,0 }; // [0] = times, [1] = level
	int fourCard[2] = { 0,0 }; // [0] = times, [1] = level
	int flush[2] = { 0,0 }; // [0] = times, [1] = level
	int straight[2] = { 0,0 }; // [0] = times, [1] = level
	// int Royal[2] = { 0,0 }; // [0] = times, [1] = level

	// check pair, triple ,fourCard
	int pair_count;
	for (int i = 0; i < a->count; i++)
	{
		pair_count = 1;
		for (int j = 0; j < i; j++) // check pair num
		{
			if (a->card[i].number == a->card[j].number)
				pair_count++;
		}
		if (pair_count == 2) // pair
		{
			pair[0]++;
			if (pair[1] < a->card[i].number)
				pair[1] = a->card[i].number;
		}
		if (pair_count == 3) // triple
		{
			triple[0]++;
			if (triple[1] < a->card[i].number)
				triple[1] = a->card[i].number;
		}
		if (pair_count == 4) // fourCard
		{
			fourCard[0]++;
			if (fourCard[1] < a->card[i].number)
				fourCard[1] = a->card[i].number;
		}
	}

	// check Flush
	int flush_count;
	for (int i = 0; i < a->count; i++)
	{
		flush_count = 1;
		for (int j = 0; j < i; j++) // check flush num
		{
			if (a->card[i].shape == a->card[j].shape)
				flush_count++;
		}
		if (flush_count == 5) // flush
		{
			flush[0]++;
			if (flush[1] < a->card[i].number) // top
				flush[1] = a->card[i].number;
		}
	}

	// check straight
	int st_count = 1;
	int *numArr = malloc(sizeof(int) * a->count);
	for (int i = 0; i < a->count; i++)
	{
		numArr[i] = a->card[i].number;
	}
	qsort(numArr, a->count, sizeof(int), compare); // ordering
	for (int i = 4; i < a->count; i++)
	{
		st_count = 1;
		for (int j = i; j > 1; j--)
		{
			if (numArr[j] == numArr[j-1] + 1) // order?
				st_count++;
			if (st_count == 5)
			{
				straight[0]++;
				if (straight[1] < numArr[i]) // top
					straight[1] = numArr[i];
			}
		}
	}

	// ★Check Rank
	printf("Rank : ");
	if (fourCard[0] > 0)
	{
		a->rank[0] = 6;
		a->rank[1] = fourCard[1];
		printf("FourCard %d\n", a->rank[1]);
	}
	else if (triple[0] > 0 && pair [0] > 0)
	{
		a->rank[0] = 5;
		a->rank[1] = triple[1];
		printf("Full House %d\n", a->rank[1]);
	}
	else if (flush[0] > 0)
	{
		a->rank[0] = 4;
		a->rank[1] = flush[1];
		printf("Flush %d\n", a->rank[1]);
	}
	else if (straight[0] > 0)
	{
		a->rank[0] = 3;
		a->rank[1] = straight[1];
		printf("Straight %d\n", a->rank[1]);
	}
	else if (triple[0] > 0)
	{
		a->rank[0] = 2;
		a->rank[1] = triple[1];
		printf("Triple %d\n", a->rank[1]);
	}
	else if (pair[0] == 2)
	{
		a->rank[0] = 1;
		a->rank[1] = pair[1];
		printf("Two Pair %d\n", a->rank[1]);
	}
	else if (pair[0] == 1)
	{
		a->rank[0] = 0;
		a->rank[1] = pair[1];
		printf("One Pair %d\n", a->rank[1]);
	}
	else
	{
		a->rank[0] = -1;
		a->rank[1] = numArr[a->count - 1];
		printf("Top %d\n", a->rank[1]);
	}
	printf("-------------------------\n");
}

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}