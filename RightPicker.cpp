#include "Card.h"
#include "RightPicker.h"

RightPicker::RightPicker(Player** pl,int ID) :Player(pl,ID) {};

void RightPicker::play()
{
	takeCard(); 
};

void RightPicker::takeCard()
{
	checkPairs((*pl)->getCard((*pl)->getHand().size()-1)); // Same as Left Picker, but we take from the end of the previous players hand not index 0

};

string RightPicker::type()
{
	return "Right Picker";
};