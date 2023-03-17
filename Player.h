#include "Card.h"
#include <vector>
using namespace std;

class Player
{
	private:
		vector<Card> hand;
	protected:
		Player* pl;
		virtual void play() = 0;
		virtual void takeCard(vector<Card>&) = 0;
		void initCheckPairs();
		void checkPairs(Card&);
	public:
		Player(Player*);
		vector<Card> getHand();

};