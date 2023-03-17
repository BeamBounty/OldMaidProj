#include "Card.h"
#include "Player.h"

class RightPicker : public Player
{
	private:

	protected:
		void play();
		void takeCard();

	public:
		RightPicker(Player* pl);
};