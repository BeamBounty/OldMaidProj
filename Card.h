// Define card types
// Card numbers
#ifndef cardHeader
#define cardHeader

class Card
{
	private:
		char type;
		int number;

	public:
		Card(char, int);
		Card(const Card&);
		Card &operator=(const Card&);
		bool operator==(const Card&);
		void setType(char);
		void setNumber(int);
		char getType() const;
		int getNumber() const;
		void print();
};

#endif