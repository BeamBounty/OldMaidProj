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
    fin.close();

    standard.shuffleCards();
};

Game::Game(string deckInput, ofstream* outputName)
{
    lastPlay = NULL;
    standard.makeDeck();

    ifstream fin(deckInput);
    outputF = outputName;

    if (fin && fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> standard;
        }
    }
    else
        cout << "File Not Found!";

    fin.close();
    standard.shuffleCards();
};

Game::~Game() // Deletes all the pointers we've created 
{
    lastPlay = NULL;
    delete lastPlay;
    //delete outputF;
    for_each(players.begin(), players.end(), [](Player* pl) {delete pl;}); // Iterates through players and "deletes" all player pointers
};

void Game::distribCards() // Distributes the cards to each player using a lambda function distribCards
{
    (* outputF) << "Standard Deck: \n" << standard << "\n";

    int i = 0;
    auto distribCards = [this,&i](Card& card1)
    {
        players[i++]->giveCard(card1);
        i %= players.size(); // Allows i to cycle between 0 and players.size()-1 and distribute cards to those players
    };

    for_each(standard.deckBegin(), standard.deckEnd(), distribCards);

}
int Game::getNumPlayers()
{
    return numPlayers;
}

int Game::getRnd()
{
    return rnd;
}

Player::LoserType Game::getLoserType()
{
    return loserType;
}


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
    
    // Set number of players (random int between 2 and 8)
    game.numPlayers = (rand() % (instructions[1] - instructions[0])) + instructions[0];

    // Set player_type based on input2.txt probabilities
    for (int i = 0; i < game.numPlayers; i++)
    {
        int randGen = rand() % 100 + 1;
        Player* ptemp;
        if (randGen < instructions[2]) 
        {
            ptemp = new LeftPicker(&game.lastPlay,i+1); 
        }
        else if (randGen < instructions[2] + instructions[3]) 
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

        game.players.push_back(ptemp); //***Can store player types and num_players for statisticskeeper here

    }
   
    return file;
};

// Plays the game, sets the pointer to the LAST created player (so player at index 0 has someone to draw from)
// Distributes cards, when a player removes all cards in their hand (getHand().size() == 0) erase them from the vector of players
// Repeat until there is only 1 player left, they will be declared the loser
// Those who hit a hand size == 0, will be declared winner in whichever round they manage to clear their hand
void Game::gamePlay() 
{

    lastPlay = players[players.size() - 1];

    
    distribCards();
    for_each(players.begin(), players.end(), [](Player* temp) { temp->initCheckPairs(); });

    int i = 0;
    rnd = 0;
    while (players.size() > 1)
    {
        if (rnd == 1000) // If infinite loop, we need disk space
        {
            (*outputF) << "NO LOSERS" << endl;
            break;
        }

        if (i == 0)
        {
            rnd++;
            (* outputF) << "---------------------------------------------------- \n";
            (* outputF) << "Round: " << rnd << endl;
            (* outputF) << "Player Count: " << players.size() << endl;
            (* outputF) << "---------------------------------------------------- \n\n";
        }
        hasWon(players[i], i); // In case of god-hand where they have only pairs in hand from start
        i %= players.size(); // hasWon will remove a player at a certain index which MAY throw i out of bounds from the player vector, %= sets it back within range of said vector

        (* outputF) << "-------------------------\n";
        (* outputF) << "Turn: " << i << "\n\n";
        (* outputF) << *players[i] << "\nAttempting to pick card from: \n" << *lastPlay << endl;
        Card temp = players[i]->play();
        (* outputF) << "Card picked: " << temp.getType() << temp.getNumber() << endl << endl;
        (* outputF) << "-------------------------\n";

        int lastIndex = i > 0 ? i - 1 : players.size() - 1;

        if (hasWon(lastPlay, lastIndex)) // Edge case where it attempts to draw from previous player that has already won, thus hand.size() = 0
        {
            lastIndex %= players.size();
            i %= players.size();
            lastIndex = lastIndex > 0 ? lastIndex - 1 : players.size() - 1; //Instead set it to pull from the player BEFORE the one that has just won
            lastPlay = players[lastIndex];
        }
        if (!hasWon(players[i], i))
        {
            lastPlay = players[i];
            i++;
        }
        i %= players.size();
    }

    // Loser determined here. Set the type in the loserType property
    
    string loser = players[0]->type();
    
    if ((loser.find("Left") == 0))
        loserType = Player::LEFT_PICKER;
    else if ((loser.find("Right") == 0))
        loserType = Player::RIGHT_PICKER;
    else if ((loser.find("Random") == 0))
        loserType = Player::RANDOM_PICKER;
    else if ((loser.find("Shuffle") == 0))
        loserType = Player::SHUFFLER;
    else loserType = Player::ERROR;

    
    
    (* outputF) << "**************************************************** \n";
    (* outputF) << "Loser: \n" << *players[0];
    //Append loser to StatisticsKeeper vector
    //players[0] is a pointer to loser
    (* outputF) << "**************************************************** \n";

}

bool Game::hasWon(Player* play, int index)
{
    if (play->getHand().size() == 0) 
    {
        (* outputF) << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++ \n";
        (* outputF) << "Won the Round: \n" << *play;
        (* outputF) << "++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n";
        players.erase(players.begin() + index);
        return true;
    }

    return false;
}