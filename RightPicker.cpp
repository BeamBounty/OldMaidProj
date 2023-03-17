#include "Card.h"
#include "RightPicker.h"

RightPicker::RightPicker(Player** pl) :Player(pl) {};

void RightPicker::play()
{
	takeCard(); //take card from previous (dont know how to determine that)
};

void RightPicker::takeCard()
{
	checkPairs(pl[0]->getHand()[getHand().size()]);
};