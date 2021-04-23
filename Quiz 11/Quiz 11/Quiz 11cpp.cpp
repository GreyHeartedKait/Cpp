/*
* Author: Kaitln Bui
* Date: 04.21.2021
* Program: Quiz 11-Soccer Team Calculator
* Purpose: Calculates the number of soccer teams one could have (depending on
* the people/team &total # of players)
*/
#include <iostream>

using namespace std;

int main() {
	int numPlayers,
		totalPlayers;
	//instructions & prompt
	cout << "Hello user! Welcome to the soccer team calculator.\n\n"
		<< "This program will tell you how many soccer teams you can have!\n"
		<< "\nPlease input how many players you want per team and\n"
		<< "the total number of players you have.\n";

	do {//user input-validation loop to ensure #/team is appropriate
		cout << "\nNumber of players per team (between 9-15): ";
		cin >> numPlayers;
	} 	while (numPlayers < 9 || numPlayers>15);

	cout << "\nTotal Number of players: "; //Letting the int modifier truncate if dec. is given
	cin >> totalPlayers;

	cout << "\nNumber of teams: " << totalPlayers / numPlayers
		<< "\nNumber of remaining players: " << totalPlayers % numPlayers<<endl;

	system("pause");
}