#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(char type, int number) 
{
	this->type = type;
	this->number = number;
};
Card::Card(const Card& card1) 
{
	this->type = card1.getType();
	this->number = card1.getNumber();
};
Card& Card::operator=(const Card& card1)
{
	this->type = card1.getType();
	this->number = card1.getNumber();
	return *this;
};

bool Card::operator==(const Card& card1)
{
	// Used if we need to check if two cards are equal to each other
	if (card1.getNumber() == this->number)
		return true;
		
	return false;
		
};
void Card::setType(char type1)
{
	this->type = type1;
};
void Card::setNumber(int num1)
{
	this->number = num1;
};
char Card::getType() const
{
	return this->type;
};
int Card::getNumber() const
{
	return this->number;
};

void Card::print()
{
	cout << type << number << " ";
}


