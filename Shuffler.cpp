#include "Card.h"
#include "Shuffler.h"
#include <vector>
#include <algorithm>
#include <string>
Shuffler::Shuffler(Player** pl,int ID) :Player(pl,ID)
{
	random = -1;
};

Card& Shuffler::play()
{
	Card temp = takeCard();
	shuffleHand();
	return temp;
};

Card& Shuffler::takeCard()
{
	if(random < 0 || random >= (*pl)->getHand().size()) //Similar to random, pick a card that is within the size of the previous players hand
		random = (rand() % (*pl)->getHand().size());  

	Card temp = (*pl)->getCard(random);
	checkPairs(temp);

	return temp;
};

string Shuffler::type()
{
	return "Shuffler Picker's Wacky Random Number: " + to_string(random);
};