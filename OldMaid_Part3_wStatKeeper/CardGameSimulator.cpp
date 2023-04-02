#include "CardGameSimulator.h"
#include "StatisticsKeeper.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


CardGameSimulator::CardGameSimulator() : totalPlayers(0), totalRounds(0), numOfGames(0) 
{
	for (int i = 0; i < 4; i++)
		losers[i] = 0;
}

void CardGameSimulator::get_user_input() // Takes and saves all user inputs
{
	string numGames;
	/*
	cout << "Enter name of Deck input file: ";
	cin >> deckInput;

	cout << "Enter name of Player input file: ";
	cin >> playerInput;

	cout << "Enter name of output file: ";
	cin >> output;
	*/
	cout << "Enter number of games to be played: ";
	cin >> numGames;

	numOfGames = stoi(numGames);

};


void CardGameSimulator::generateGames() 
{
	ofstream outputFile("Output.txt"); // Create the file write to //**replaced output

	keeper.setNumGames(numOfGames);

	for (int i = 0; i < numOfGames ; i++) 
	{
		outputFile << "GAME " << (i + 1) << endl;
		Game game1("Input.txt", &outputFile); // Initialize deck from user given file & pass it file to output the deck to
		ifstream fin("Input2.txt");

		if (fin && fin.is_open())
		{
			fin >> game1; // Read all of the player(s) information (amount, probabilities, etc)
			game1.gamePlay(); 
		}

		keeper.accumulateRounds(game1.getRnd());
		keeper.accumulatePlayers(game1.getNumPlayers());
		keeper.addLoser(game1.getLoserType());
	}

	keeper.printStats(outputFile);

	outputFile.close(); // Close file when done
}

int CardGameSimulator::getNumOfGames()
{
	return numOfGames;
}

int CardGameSimulator::getTotalRounds()
{
	return totalRounds;
}

