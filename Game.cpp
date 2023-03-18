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

Game::Game() // Reads in information from input.txt, intializes a deck of cards, and then shuffles them
{
    lastPlay = NULL;
    standard.makeDeck();
	
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

void Game::distribCards() // Distributes the cards to each player using a lambda function distribCards
{
    std::cout << "Standard Deck: \n" << standard << "\n";

    int i = 0;
    auto distribCards = [this,&i](Card& card1)
    {
        players[i++]->giveCard(card1);
        i %= players.size(); // Allows i to bounce between 0 and 6 and distribute cards to those players
    };

    for_each(standard.deckBegin(), standard.deckEnd(), distribCards);

};

// Reads in all data from input2.txt (for Project Part 2), also checks to see if players are between certain intervals to determine which kind of player should be created
// Once created they are pushed onto the vector of players
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
        Player* ptemp;
        if (randGen < instructions[2]) //randgen < 30 
        {
            ptemp = new LeftPicker(&game.lastPlay,i+1); 
        }
        else if (randGen < instructions[2] + instructions[3]) // randgen < 30 + 20
        {
            ptemp = new RightPicker(&game.lastPlay,i+1);
        }
        else if (randGen < instructions[2] + instructions[3] + instructions[4])
        {
            ptemp = new Random(&game.lastPlay,i+1);
        }
        else
        {
            ptemp = new Shuffler(&game.lastPlay,i+1);
        }

        game.players.push_back(ptemp);
    }
   
    return file;
};

// Plays the game, sets the pointer to the LAST created player (so player at index 0 has someone to draw from)
// Distributes cards, when a player removes are cards in their hand (getHand().size() == 0) erase them from the vector of players
// Repeat until there is only 1 player left, they will be declared the loser
// Those who hit a hand size == 0, will be declared winner in whichever round they manage to clear their hand
void Game::gamePlay() 
{
    lastPlay = players[players.size()-1];

    int i = 0;
    distribCards();
    for_each(players.begin(), players.end(), [](Player *temp) { temp->initCheckPairs(); });
    int rnd = 0;
    while (players.size() > 1)
    {
        if (i == 0)
        {
            rnd++;
            std::cout << "---------------------------------------------------- \n";
            std::cout << "Round: " << rnd << endl;
            std::cout << "Player Count: " << players.size() << endl;
            std::cout << "---------------------------------------------------- \n\n";
        }

        if (players[i]->getHand().size() == 0) // In-case of god hand where they win after being dealt
        {
            std::cout << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++ \n";
            std::cout << "Won the Round: \n" << *players[i];
            std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n";
            players.erase(players.begin() + i);
        }

        players[i]->play();
        if (players[i]->getHand().size() == 0)
        {
            std::cout << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++ \n";
            std::cout << "Won the Round: \n" << *players[i];
            std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n";
            players.erase(players.begin() + i);
        }
        else
        {
            lastPlay = players[i];
            i++;
            i %= players.size();
        }
        std::cout << *players[i] << endl;
    }
    std::cout << "**************************************************** \n";
    std::cout <<"Loser: \n"<< *players[0];
    std::cout << "**************************************************** \n";

};