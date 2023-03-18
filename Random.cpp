#include "Card.h"
#include "Random.h"
#include <time.h>

Random::Random(Player** pl,int ID):Player(pl,ID) {};

void Random::play()
{
	takeCard(); 
};

void Random::takeCard()
{
	int random = (rand() % (*pl)->getHand().size()); // Choose a random number based of the size of the last persons hand, use that to pick a card

	checkPairs((*pl)->getCard(random));

};

string Random::type()
{
	return "Random Picker";
};