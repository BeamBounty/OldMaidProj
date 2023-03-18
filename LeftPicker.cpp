#include "Card.h"
#include "LeftPicker.h"

LeftPicker::LeftPicker(Player** pl,int ID):Player(pl,ID){};

void LeftPicker::play()
{
	takeCard(); 
};

void LeftPicker::takeCard()
{
	checkPairs((*pl)->getCard(0)); // Grab a card from the previous player at position 0
};

string LeftPicker::type()
{
	return "Left Picker";
};