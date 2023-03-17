#include "Deck.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <string>
using namespace std;

Deck::Deck(){};

Deck::Deck(Deck& deck1)
{
	this->standard = deck1.getDeck();
};
Deck& Deck::operator=(Deck& deck1)
{
	this->standard = deck1.getDeck();
	return *this;
};
void Deck::operator+=(Card& card1)
{
	standard.push_back(card1);
};
void Deck::operator-=(Card& card1)
{
	standard.erase(remove(standard.begin(), standard.end(), card1),standard.end());
};

vector<Card> &Deck:: getDeck()
{
	return standard;
};

void Deck::shuffleCards()
{
	random_shuffle(standard.begin(), standard.end());
};

istream& operator>>(istream& in, Deck& deck1)
{
	string deck; // For when we implement another deck besides Standard, to grab the deck type 
	in >> deck; 

	string command; // To read the ADD or REMOVE command
	in >> command;
	
	string num; // AMOUNT to ADD/REMOVE
	in >> num;

	int number = stoi(num); // Parse amount into an int

	for (int i = 0; i < number; i++)
	{
		string suit; // card suit
		in >> suit;

		string cNum; // card number
		in >> cNum;

		int cNumber = stoi(cNum); // Parse int card number

		Card cTemp(suit[0], cNumber); // Intialize said card object to be added OR removed 

		if (command == "r") // generic checks, if r then -= to remove the card from the deck otherwise += to add
		{
			deck1 -= cTemp;
		}
		else if (command == "a")
		{
			deck1 += cTemp;
		}
	}
	return in;
};

ostream& operator<<(ostream& out, Deck& deck1)
{
	// Lambda function which allows to take a card object by reference and print it
	auto printDeck = [&out](Card& card1) { card1.print(); }; 
	for_each(deck1.standard.begin(), deck1.standard.end(), printDeck);
	return out;
};

void Deck::makeDeck() // If decks get very large WILL NEED TO MAKE CHANGES TO THIS FOR SPACE COMPLEXITY
{
	// A loop to intialize cards 1 ~ 13 for Clubs, Diamonds, Hearts, and Spades
	// Could use a for each loop but would require another frankly unnecessary lambda function
	for (int i = 1; i <= 13; i++)
	{
		Card Clubs('C', i);
		Card Diamonds('D', i);
		Card Hearts('H', i);
		Card Spades('S', i);

		*this += Clubs;
		*this += Diamonds;
		*this += Hearts;
		*this += Spades;
	}
};

vector<Card>::iterator Deck::deckBegin()
{
	return standard.begin();
};

vector<Card>::iterator Deck::deckEnd()
{
	return standard.end();
};
