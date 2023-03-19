#include "Deck.h"
#include "Player.h"
#include "Card.h" //Maybe
#include <iostream>
#include <vector>

class Game
{
	private:
		Player* lastPlay;
		Deck standard;
		vector<Player*> players; 
	public:

		Game();
		
		void distribCards();

		friend istream& operator>>(istream&, Game&);

		void gamePlay();
		bool hasWon(Player*, int); 
};