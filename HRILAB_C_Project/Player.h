// Player
#include "Card.h"

struct Player
{
	struct Card card[7]; // Poker's card num is 7
	int money; // money for betting
	int bet_m; // betting money
};

void initPlayer(struct Player *p); // init player
void bettingPlayer(struct Player *p); // betting
void viewPlayerCard(struct Player *p); // view Player card
/* ----------------- */ 
void initComputer(struct Player *c); // init cpu
void bettingComputer(struct Player *c); // auto betting
void viewComputerCard(struct Player *c); // view Computer card

// all