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
		virtual void takeCard() = 0;
		void checkPairs(Card&);
		virtual string type() = 0;

	public:
		Player();
		void initCheckPairs();
		virtual void play() = 0;
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