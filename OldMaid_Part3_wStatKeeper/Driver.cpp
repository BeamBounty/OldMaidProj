#include <iostream>
#include <fstream>
#include "Card.h" 
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include "CardGameSimulator.h"
#include <vector>
using namespace std;

int main()
{
    srand(time(0));

    CardGameSimulator cgs;

    cgs.get_user_input();
    cgs.generateGames();

};
