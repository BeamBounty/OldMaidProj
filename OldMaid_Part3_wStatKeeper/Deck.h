#ifndef DeckH
#define DeckH

#include "Card.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Deck
{
private:
	vector<Card> standard;

public:
	Deck();
	Deck(Deck&);
	Deck& operator=(Deck&);
	void operator+=(Card&);
	void operator-=(Card&);
	void makeDeck();
	vector<Card>& getDeck();
	void shuffleCards(); 
	vector<Card>::iterator deckBegin();
	vector<Card>::iterator deckEnd();
	 

	friend istream& operator>>(istream&,Deck&);
	friend ostream& operator<<(ostream&, Deck&);

};

#endif // !DeckH