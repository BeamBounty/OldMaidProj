#include "CardGameSimulator.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void CardGameSimulator::get_user_input() // Takes and saves all user inputs
{
	string numGames;

	cout << "Enter name of Deck input file: ";
	cin >> deckInput;

	cout << "Enter name of Player input file: ";
	cin >> playerInput;

	cout << "Enter name of output file: ";
	cin >> output;

	cout << "Enter number of games to be played: ";
	cin >> numGames;

	numOfGames = stoi(numGames);

};

void CardGameSimulator::generateGames() 
{
	ofstream outputFile(output); // Create the file write to
	
	for (int i = 0; i < numOfGames; i++) 
	{
		outputFile << "GAME " << (i + 1) << endl;
		Game game1(deckInput,&outputFile); // Initialize deck from user given file & pass it file to output the deck to
		ifstream fin(playerInput);

		if (fin && fin.is_open())
		{
			fin >> game1; // Read all of the player(s) information (amount, probabilities, etc)
			game1.gamePlay(); 
		}
	}

	outputFile.close(); // Close file when done
};

