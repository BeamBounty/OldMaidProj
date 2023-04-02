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

	public:
		Player();
		~Player();
		Player(Player**, int);
		void initCheckPairs();
		virtual Card& play() = 0; // Allows us to print into the output file (can't print it otherwise if not Card&)
		virtual string type() = 0;
		vector<Card> getHand();
		void giveCard(Card&);
		friend ostream& operator<<(ostream&,Player&);
		void cardRemove(Card&);
		void shuffleHand();
		Card& getCard(int);
		int getID();
		enum LoserType { LEFT_PICKER, RIGHT_PICKER, RANDOM_PICKER, SHUFFLER, ERROR  };
};
#endif // !PlayerH