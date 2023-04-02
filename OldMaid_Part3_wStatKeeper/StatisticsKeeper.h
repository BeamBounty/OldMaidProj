#ifndef StatisticsKeeper_H
#define StatisticsKeeper_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Game.h"
using namespace std;

class StatisticsKeeper {

private:
	int numGames;
	int accumulatedRounds;
	int accumulatedPlayers;
	int losers[4];

public:
	StatisticsKeeper();
	void printStats(ofstream&);

		// Initialize member variables as needed
	void setNumGames(int);
	void accumulateRounds(int);
	void accumulatePlayers(int);
	void addLoser(Player::LoserType);






	
};

#endif