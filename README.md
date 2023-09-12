Object Oriented Programming 
Old Maid Project

The objective of the game is to finish the game with no cards in hand.
Whomever ends the game with the final card (a pair cannot be made), is declared the loser.

This game is FULLY AUTOMATED. 
The amount of players and type of players are chosen at random at the start of every game.

The amount of players can vary from 2 to 8 per game.
The type of players are:
- Left Picker: Always picks the left most card in the prior players hand
- Right Picker: Always pick the RIGHT most card in the prior players hand
- Shuffler: Will pick the same position to pick from until the position now longer exsists, then it will choose a new one
- Random: It picks a card, within the bounds of the previous players hand, at random

Statistics are kept per game and are shown in the output file.

The input files defines any changes made to the deck, for example:

Standard
r 3 
C 12 D 12 H 12

That input states that from the STANDARD deck of cards, REMOVE 3 cards, with those 3 cards being 12 of Clubs, 12 of Diamonds, and 12 of Hearts.
Those cards will now not be in play for any of the games played during that runtime session.

Other commands for the input file include:
- a : add cards

