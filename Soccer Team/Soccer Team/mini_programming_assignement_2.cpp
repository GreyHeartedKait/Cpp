/*
* This progam creates a soccer team using a soccer player structure and has functions to
* 1. list player information
* 2. total all of the players' season goals
* 
* CS 132 - Wood
* By Kaitlyn Bui
* 01.13.2021
*/

#include <iostream>
using namespace std;

struct Soccer_Player {
	string name;
	int jersey_number;
	int goals_scored;
};

void print_player_info(const Soccer_Player&);
int total_goals(const Soccer_Player[], int);

int main() {
	const int TEAM_SIZE = 5;
	Soccer_Player team[TEAM_SIZE];

	//inputting all the team's players
	team[0] = { "Pele", 5, 16 };
	team[1] = { "Lionel", 53, 14 };
	team[2] = { "Diego", 25, 25 };
	team[3] = { "Johan", 12, 2 };
	team[4] = {"Zinedine", 88, 32};

	//print out all player information
	cout << "Team players: " << endl
		<<"---------------------"<<endl;
	for (int i = 0; i < TEAM_SIZE; i++) {
		print_player_info(team[i]);
		cout << endl<<endl;
	}
	
	//print out team total goals
	cout << "The team made " << total_goals(team, TEAM_SIZE) << " total goals this season.";

	return 0;
}

//will print out the information of a player
void print_player_info(const Soccer_Player &player) {
	cout<< "Name: " << player.name
		<< "\nNumber: " << player.jersey_number
		<< "\nNumer of goals scored this season: " << player.goals_scored;
}

//sums and returns total goals
int total_goals(const Soccer_Player players[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += players[i].goals_scored;
	}

	return total;
}