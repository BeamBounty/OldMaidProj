#include "StatisticsKeeper.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Game.h"

StatisticsKeeper::StatisticsKeeper() : accumulatedRounds(0), accumulatedPlayers(0)
{
	for (int i = 0; i < 4; i++)
		losers[i] = 0;
}

void StatisticsKeeper::printStats(ofstream& outFile)
{

	int myWidth = 30;

	outFile.fill('.');
	outFile << "\n\n\n##############---Final Statistics---#############\n" << endl;
	outFile << left << setw(myWidth) << "Games played: " << "  " << numGames << endl;
	outFile << setw(myWidth) << "Rounds Played: " << "  " << accumulatedRounds << endl;
	outFile << setw(myWidth) << "Average Rounds Per Game: " << "  " << fixed << setprecision(1)  << accumulatedRounds / (double)numGames << endl;
	outFile << setw(myWidth) << "Players Generated : " << "  " << accumulatedPlayers << endl;
	outFile << setw(myWidth) << "Average Players Per Game: " << "  " << accumulatedPlayers / (double)numGames << endl;

	double totalLosers = numGames;
	double leftPercent = losers[Player::LEFT_PICKER] / totalLosers * 100;
	double rightPercent = losers[Player::RIGHT_PICKER] / totalLosers * 100;
	double randomPercent = losers[Player::RANDOM_PICKER] / totalLosers * 100;
	double shufflerPercent = losers[Player::SHUFFLER] / totalLosers * 100;

	outFile << "\n------Loser Statistics------\n";
	outFile << setw(myWidth) << left << "Left Picker" << "  " << setprecision(1) << fixed << leftPercent << "%" << endl;
	outFile << setw(myWidth) << "Right Picker" << "  " << rightPercent << "%" << endl;
	outFile << setw(myWidth) << "Random Picker" << "  " << randomPercent << "%" << endl;
	outFile << setw(myWidth) << "Shuffler Picker" << "  " << shufflerPercent << "%" << endl;

	outFile << "\n#################################################" << endl;
}

void StatisticsKeeper::setNumGames(int gameCount)
{
	numGames = gameCount;
}


void StatisticsKeeper::addLoser(Player::LoserType loser)
{
	losers[loser]++;
}

void StatisticsKeeper::accumulateRounds(int currRounds)
{
	accumulatedRounds += currRounds;
	
}

void StatisticsKeeper::accumulatePlayers(int currPlayers)
{
	accumulatedPlayers += currPlayers;
}

