#include "Card.h"
#include "Player.h"

class RightPicker : public Player
{
	private:

	protected:
		Card& play();
		Card& takeCard();
		string type();

	public:
		RightPicker(Player** pl,int);
};