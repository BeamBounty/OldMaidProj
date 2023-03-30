#include "Card.h"
#include "Player.h"

class Random : public Player
{
	private:

	protected:
		Card& play();
		Card& takeCard();
		string type();

	public:
		Random(Player** pl,int);
};