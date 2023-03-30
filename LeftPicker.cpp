#include "Card.h"
#include "LeftPicker.h"

LeftPicker::LeftPicker(Player** pl,int ID):Player(pl,ID){};

Card& LeftPicker::play()
{
	return takeCard(); 
};

Card& LeftPicker::takeCard()
{
	Card temp = (*pl)->getCard(0); // Grab a card from the previous player at position 0
	checkPairs(temp);

	return temp;
};

string LeftPicker::type()
{
	return "Left Picker";
};