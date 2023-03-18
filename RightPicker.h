#include "Card.h"
#include "Player.h"

class RightPicker : public Player
{
	private:

	protected:
		void play();
		void takeCard();
		string type();

	public:
		RightPicker(Player** pl,int);
};