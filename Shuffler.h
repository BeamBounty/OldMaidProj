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
		string type();
	public:
		Shuffler(Player** pl,int);


};