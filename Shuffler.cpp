#include "Card.h"
#include "Shuffler.h"
#include <vector>
#include <algorithm>
#include <string>
Shuffler::Shuffler(Player** pl,int ID) :Player(pl,ID)
{
	random = -1;
};

void Shuffler::play()
{
	takeCard(); 
	shuffleHand();
};

void Shuffler::takeCard()
{
	if(random < 0 || random >= (*pl)->getHand().size()) //Similar to random, pick a card that is within the size of the previous players hand
		random = (rand() % (*pl)->getHand().size());  

	checkPairs((*pl)->getCard(random));

};

string Shuffler::type()
{
	return "Shuffler Picker's Wacky Random Number: " + to_string(random);
};