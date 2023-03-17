#include "Card.h"
#include <vector>
#include <iostream>
using namespace std;

class Player
{
	private:
		vector<Card> hand;
	
	protected:
		Player** pl;
		virtual void takeCard() = 0;
		void checkPairs(Card&);

	public:
		void initCheckPairs();
		virtual void play() = 0;
		Player(Player**);
		vector<Card> getHand();
		void giveCard(Card&);
		friend ostream& operator<<(ostream&,Player&);
};