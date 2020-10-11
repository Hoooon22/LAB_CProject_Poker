// Player
#include "Card.h"

struct Player
{
	struct Card card[7]; // Poker's card num is 7
	int count; // number of having card
	int open[7]; // check opening card (0 == closed, 1 == opened)
	int money; // money for betting
	int bet_m; // betting money
	int rank[2]; // [0] = rank, [1] = level
};
/* ---------------------------------------------------- */
void initPlayer(struct Player *p); // init player
void bettingPlayer(struct Player *p); // betting

/* ---------------------------------------------------- */
void initComputer(struct Player *c); // init cpu
void bettingComputer(struct Player *c); // auto betting

/* ---------------------------------------------------- */
// all -> a
void viewCard(struct Player *a); // view card
void getCard(struct Player *a, struct Deck *deck); // give card
void openCard(struct Player *a, int num, int open_n); // open card
void checkRank(struct Player* a); // check Ranks of Hands -> (0, pair), (1, two Pair), (2, triple), (3, straight), (4, flush), (5, full house), (6, fourCard)
int compare(const void* a, const void* b);