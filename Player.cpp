#include "Player.h"
#include "Card.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

Player::Player() // Default constructor, just to intialize them to something until they're assigned proper values
{
	this->pl = NULL;
	this->ID = -1;
};

Player::Player(Player** pl, int ID) // Give each player their pointer to the previous player and a unique ID# 
{
	this->pl = pl;
	this ->ID = ID;
}

Player::~Player()
{
	pl = NULL;
	delete pl;
};
vector<Card> Player::getHand()
{
	return hand;
};

void Player::initCheckPairs() // Used ONCE at the start of the game to remove any pairs they may have after being dealt their hand
{

	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = i+1; j < hand.size(); j++)
		{
			if (hand[i] == hand[j])
			{
				hand.erase(hand.begin() + j);
				hand.erase(hand.begin() + i);
				j--;
			}
		}
	};
};

// What we use AFTER they have discarded all intial pairs, checks incoming card against the card in their hand. If the numbers match, discard the pair, if not, add the card to the hand.
void Player::checkPairs(Card& taken) 
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i] == taken)
		{
			hand.erase(hand.begin() + i);
			return;
		}
	}

	hand.push_back(taken);
};

void Player::giveCard(Card& card)
{
	hand.push_back(card);
};

ostream& operator<<(ostream& out, Player& players) // Prints out each players hand, what kind of player they are, and their unique ID
{
	out << "Player ID: " << players.ID << endl;
	out << players.type() << endl;

	auto printHand = [&out](Card& card1) { out << card1.getType() << card1.getNumber() << " "; };
	for_each(players.hand.begin(), players.hand.end(), printHand);
	if (players.hand.size() == 0) 
	{
		out << "empty";
	}
	out << endl;

	return out;
};

void Player::cardRemove(Card& card)
{
	checkPairs(card);
};

void Player::shuffleHand()
{
	random_shuffle(hand.begin(), hand.end());
};

Card& Player::getCard(int cdNum)
{
	Card temp = hand[cdNum];
	cardRemove(temp);
	return temp;
};

int Player::getID()
{
	return ID;
};