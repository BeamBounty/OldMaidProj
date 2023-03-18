#include <iostream>
#include <fstream>
#include "Card.h" 
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include <vector>
using namespace std;

int main()
{
    // TEST DRIVER, USING FOR DEBUGGING
    srand(time(0));

    ifstream amtPlayers("Input2.txt");
    
    Game game1;
    
    amtPlayers >> game1;

    game1.gamePlay();

};
