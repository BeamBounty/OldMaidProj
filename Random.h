#include "Card.h"
#include "Player.h"

class Random : public Player
{
	private:

	protected:
		void play();
		void takeCard();
		string type();

	public:
		Random(Player** pl,int);
};