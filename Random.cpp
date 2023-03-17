#include "Card.h"
#include "Random.h"
#include <time.h>

Random::Random(Player** pl) :Player(pl) {};

void Random::play()
{
	takeCard(); //take card from previous (dont know how to determine that)
};

void Random::takeCard()
{
	int random = 1 + (rand() % pl->getHand().size()); // need to make that PREVIOUS persons hand.size AND how to get access to hand
	checkPairs(pl[0]->getHand()[random]);
};