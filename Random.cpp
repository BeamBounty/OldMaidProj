#include "Card.h"
#include "Random.h"
#include <time.h>

Random::Random(Player** pl,int ID):Player(pl,ID) {};

Card& Random::play()
{
	return takeCard(); 
};

Card& Random::takeCard()
{
	int random = (rand() % (*pl)->getHand().size()); // Choose a random number based of the size of the last persons hand, use that to pick a card
	Card temp = (*pl)->getCard(random);
	checkPairs(temp);

	return temp;
};

string Random::type()
{
	return "Random Picker";
};