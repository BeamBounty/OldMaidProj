#include "Card.h"
#include "LeftPicker.h"

LeftPicker::LeftPicker(Player* pl):Player(pl){};

void LeftPicker::play()
{
	takeCard(); //take card from previous (dont know how to determine that)
};

void LeftPicker::takeCard()
{
	checkPairs(pl->getHand()[0]);
};