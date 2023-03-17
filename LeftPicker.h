#include "Card.h"
#include "Player.h"

class LeftPicker : public Player
{
	private:

	protected:
		void play();
		void takeCard();

	public:
		LeftPicker(Player* pl);
};