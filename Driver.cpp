#include <iostream>
#include <fstream>
#include "Card.h" 
#include "Deck.h"
#include <vector>
using namespace std;

int main()
{

    srand(time(0));

    Deck masterDeck;

    ifstream fin("Input.txt");
    int gamers = rand() % 7 + 2; // Generates a random amount of players from 2 to 7
    
    vector<Deck> players = vector<Deck>(gamers); // Intialize a vector players (not helpful now, will be later when we need to start grabbing grabs and creating pairs)

    masterDeck.makeDeck();

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> masterDeck;
        }
    }

    masterDeck.shuffleCards();
    //cout << masterDeck.getDeck().size() << "\n"; // A test line to be sure deck was still generating 52 cards after shuffle
    cout << "Standard Deck: \n" << masterDeck << "\n";

    int i = 0;
    auto distribCards = [&players, &masterDeck, gamers, &i](Card& card1) 
    {
        players[i++] += card1;
        //masterDeck -= card1; // Also a test line, commented out because we DO NOT want to erase cards while distributing, creates an uneven distribution of cards 
        i %= gamers; // Allows i to bounce between 0 and 6 and distribute cards to those players
    };

    for_each(masterDeck.deckBegin(), masterDeck.deckEnd(), distribCards);

    for (int i = 0; i < players.size(); i++)
    {
        cout << "Player " << i+1 << ":\n" << players[i] << "\n";
    }    
};
