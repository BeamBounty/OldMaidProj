#include "Deck.h"
#include "Player.h"
#include "Card.h" //Maybe
#include <iostream>
#include <vector>

class Game
{
	private:
		Player** lastPlay;
		Deck standard;
		vector<Player*> players; 
	public:

		Game();

		// distribute cards from deck
			// intializing players with their hands
			// Same thing as in driver kinda, remove from deck, pass to player(s) "Hand" vector
			// Update pointer 
		
		void distribCards();

		friend istream& operator>>(istream&, Game&);

		// Read in input and spawn players (might need a method for this, maybe squeeze it into distrib cards method)

		void gamePlay();
};