#ifndef PlayerH
#define PlayerH

#include "Card.h"
#include <vector>
#include <iostream>
using namespace std;

class Player
{
	private:
		vector<Card> hand;
		int ID;
	protected:
		Player** pl;
		virtual Card& takeCard() = 0; // Allows us to print into the output file (can't print it otherwise if not Card&)
		void checkPairs(Card&);
		virtual string type() = 0;

	public:
		Player();
		~Player();
		void initCheckPairs();
		virtual Card& play() = 0; // Allows us to print into the output file (can't print it otherwise if not Card&)
		Player(Player**,int);
		vector<Card> getHand();
		void giveCard(Card&);
		friend ostream& operator<<(ostream&,Player&);
		void cardRemove(Card&);
		void shuffleHand();
		Card& getCard(int);
		int getID();
};
#endif // !PlayerH