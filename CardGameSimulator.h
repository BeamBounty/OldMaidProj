#pragma once
// MIGHT NOT NEED HEADER FILE
// get_user_input() 
	//Takes user specified values: 
		//Number of games to be played 
		//Name of input files and output file
		//Prompts through terminal

#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

class CardGameSimulator
{
	private:
		string deckInput;
		string playerInput;
		string output;
		int numOfGames;

	protected:
	public:
		void get_user_input();
		void generateGames();
};