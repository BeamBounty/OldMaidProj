#ifndef GameH
#define GameH

#include "Deck.h"
#include "Player.h"
#include "Card.h" //Maybe
#include <iostream>
#include <vector>
#include <fstream>

class Game
{
	private:
		Player* lastPlay;
		Deck standard;
		vector<Player*> players; 
		ofstream* outputF;
	public:

		Game();
		Game(string,ofstream*);
		~Game();
		void distribCards();

		friend istream& operator>>(istream&, Game&);

		void gamePlay();
		bool hasWon(Player*, int); 
};

#endif