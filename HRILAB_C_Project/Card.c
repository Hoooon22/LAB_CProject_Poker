#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

#include "Card.h"

void initDeck(struct Deck *deck) // init + suffle the deck
{
	deck->count = 0;
	int num = 0;

	for (int i = 0; i < 4; i++) // initial deck
	{
		for (int j = 1; j <= 13; j++)
		{
			switch (i) // init - shape
			{
			case 0:
				deck->card[num].shape = "¢¼";
				break;
			case 1:
				deck->card[num].shape = "¡ß";
				break;
			case 2:
				deck->card[num].shape = "¢¾";
				break;
			case 3:
				deck->card[num].shape = "¢À";
				break;
			}
			deck->card[num].number = j; // init - number
			num++;
		}
	}

	shuffle(deck); // suffle
}

void shuffle(struct Deck *deck) {
	srand((unsigned int)time(NULL));
	struct Card c1;
	int rn; 

	for (int i = deck->count; i < 52; i++) {
		rn = rand() % (52 - i);
		c1 = deck->card[i]; 
		deck->card[i] = deck->card[rn];
		deck->card[rn] = c1;
	} 
}
