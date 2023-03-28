#pragma once
// MIGHT NOT NEED HEADER FILE
// get_user_input() 
	//Takes user specified values: 
		//Number of games to be played 
		//Name of input files and output file
		//Prompts through terminal

#include <iostream>
#include <fstream>
using namespace std;

class CardGameSimulator
{
	private:
		ifstream input;
		ofstream output;
	protected:
	public:

		void get_user_input();
		void getInputF();
		void setInputF();
		void getOutputF();
		void setOutputF();

};