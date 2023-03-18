#include "Card.h"
#include "Player.h"

class LeftPicker : public Player
{
	private:

	protected:
		void play();
		void takeCard();
		string type();
	public:
		LeftPicker(Player**,int);
};