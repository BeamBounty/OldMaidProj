#include "Card.h"
#include "Player.h"

class Random : public Player
{
	private:

	protected:
		void play();
		void takeCard();

	public:
		Random(Player* pl);
};