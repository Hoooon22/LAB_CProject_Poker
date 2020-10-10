#include <stdio.h>
#include "Game.h"

int main()
{
	static struct Player p;
	static struct Computer c[3];
	static struct Deck deck;

	start(&deck, &p, &c);



	return 0;
}