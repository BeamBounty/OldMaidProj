#include "Card.h"
#include "Player.h"
#include <vector>

class Shuffler : public Player
{
	private:
		int random;
	protected:
		Card& play();
		Card& takeCard();
		string type();
	public:
		Shuffler(Player** pl,int);


};