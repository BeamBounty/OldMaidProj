#include "Card.h"
#include "Player.h"

class LeftPicker : public Player
{
	private:

	protected:
		Card& play();
		Card& takeCard();
		string type();
	public:
		LeftPicker(Player**,int);
};