#include "Card.h"
#include "RightPicker.h"

RightPicker::RightPicker(Player** pl,int ID) :Player(pl,ID) {};

Card& RightPicker::play()
{
	return takeCard(); 
};

Card& RightPicker::takeCard()
{
	Card temp = (*pl)->getCard((*pl)->getHand().size() - 1); // Same as Left Picker, but we take from the end of the previous players hand not index 0
	checkPairs(temp);

	return temp;
};

string RightPicker::type()
{
	return "Right Picker";
};