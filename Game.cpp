#include "Game.h" 
#include "Deck.h"
#include "Player.h"
#include "LeftPicker.h"
#include "RightPicker.h"
#include "Shuffler.h"
#include "Random.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

Game::Game()
{
    lastPlay = { NULL };
	standard.makeDeck();

	cout << "Watch my clips" << endl;
	
    ifstream fin("Input.txt");
    
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> standard;
        }
    }

    standard.shuffleCards();
};

void Game::distribCards()
{
    cout << "Standard Deck: \n" << standard << "\n";

    int i = 0;
    auto distribCards = [this,&i](Card& card1)
    {
        players[i++]->giveCard(card1);
        //masterDeck -= card1; // Also a test line, commented out because we DO NOT want to erase cards while distributing, creates an uneven distribution of cards 
        i %= players.size(); // Allows i to bounce between 0 and 6 and distribute cards to those players
    };

    for_each(standard.deckBegin(), standard.deckEnd(), distribCards);

    for (int i = 0; i < players.size(); i++)
    {
        cout << "Player " << i + 1 << ":\n" << players[i] << "\n";
    }
};

istream& operator>>(istream& file, Game& game)
{
    /*
        Appendix:
        Index 0 = Minimum amount of players 
        Index 1 = MAXIMUM amount of players 
        Index 2 = Probability of Left Picker 
        Index 3 = Prob. of Right Picker
        Index 4 = Prob. of Random Picker
        Index 5 = Prob. of Shuffler 

        Assume Indexes 2 ~ 5 are INTEGER values and SUM to 100 
    */

    vector<int> instructions(6);
    string temp;
    for (int i = 0; i < instructions.size(); i++)
    {
        file >> temp;
        instructions[i] = stoi(temp);
    };

    int numPlayers = (rand() % (instructions[1] - instructions[0])) + instructions[0];

    for (int i = 0; i < numPlayers; i++)
    {
        int randGen = rand() % 100 + 1;
        Player* temp;
        if (randGen <= 100 && randGen >= 100 - instructions[2])
        {

            temp = &LeftPicker(game.lastPlay);
        }
    }


    return file;
};

void Game::gamePlay()
{
    lastPlay[0] = players[players.size()-1];
    int i = 0;
    distribCards();
    for_each(players.begin(), players.end(), [](Player temp) { temp.initCheckPairs(); });

    while (players.size() > 1)
    {
        players[i]->play();
        if (players[i]->getHand().size() == 0)
        {
            players.erase(players.begin() + i);
        }
        else
        {
            lastPlay[0] = players[i];
            i++;
        }
    }
};