#pragma once
// get_user_input() 
	//Takes user specified values: 
		//Number of games to be played 
		//Name of input files and output file
		//Prompts through terminal

#include "Game.h"
#include "StatisticsKeeper.h"
#include <iostream>
#include <fstream>
#include "Player.h"
 
using namespace std;

class CardGameSimulator
{
	public:
		CardGameSimulator();
		void get_user_input();
		void generateGames();
		int getNumOfGames();
		int getTotalRounds();
	
	private:
	
		string deckInput;
		string playerInput;
		string output;
		int numOfGames;
		int totalRounds;
		int totalPlayers;
		int losers[4];
		StatisticsKeeper keeper;
};