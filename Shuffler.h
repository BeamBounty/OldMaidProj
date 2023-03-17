#include "Card.h"
#include "Player.h"
#include <vector>

class Shuffler : public Player
{
	private:
		int random;
	protected:
		void play();
		void takeCard();
	
	public:
		Shuffler(Player* pl);


};