// Card

struct Card // Card
{
	char *shape; // ¢¼, ¡ß, ¢¾, ¢À
	int number; // 1~13
};

struct Deck // Deck
{
	struct Card card[52]; // number of card is 52
	int count; // number of using card
};

void initDeck(struct Deck *deck); // init + suffle the deck
void shuffle(struct Deck *deck); // count ~ last
struct Card giveCard(struct Deck *deck); // give card to player (and count++)