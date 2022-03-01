/* Rock Paper Scissors
* This class creates a RPSMove that can be printed and compared to other moves (to see who wins).
* 
* By Kaitlyn Bui
* 01.27.2022, Version 1
*/
#pragma once
#include <string>
#include <fstream>

class RPSMove
{
private:
	std::string name;

	//helper functions
	std::string randomMove();

public:
	RPSMove(std::string);
	RPSMove();

	int Vs(const RPSMove&) const;
	bool validMove(std::string&);

	friend std::ostream& operator<< (std::ostream&, const RPSMove&);
	friend std::istream& operator>> (std::istream&, RPSMove&);
};


void toLower(std::string&);
void makeTrim(std::string& x);


