#include "Card.h"
#include "Shuffler.h"

Shuffler::Shuffler(Player** pl) :Player(pl)
{
	random = 1 + (rand() % getHand().size()); // need to make that PREVIOUS persons hand.size AND how to get access to hand
};
void Shuffler::play()
{
	takeCard(); //take card from previous (dont know how to determine that)
};

void Shuffler::takeCard()
{

	checkPairs(pl[0]->getHand()[random]);
};