#include "Player.h"
#include "Card.h"
#include <vector>
#include <algorithm>
using namespace std;

Player::Player(Player* pl)
{
	this->pl = pl;
}

vector<Card> Player::getHand()
{
	return hand;
};
void Player::initCheckPairs()
{

	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = 0; j < hand.size(); j++)
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


