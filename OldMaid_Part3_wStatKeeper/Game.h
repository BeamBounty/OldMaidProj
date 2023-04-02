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
		int numPlayers;
		int rnd;
		Player::LoserType loserType;
		
	public:

		Game();
		Game(string,ofstream*);
		~Game();
		void distribCards();
		int getNumPlayers();
		int getRnd();
		Player::LoserType getLoserType();

		friend istream& operator>>(istream&, Game&);

		void gamePlay();
		bool hasWon(Player*, int); 
};

#endif