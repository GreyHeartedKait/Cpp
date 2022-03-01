/* Rock Paper Scissors
* by Kaitlyn Bui 
* 01.27.2022, version 1
*/
#include "RPSMove.h"
#include <iostream>

using namespace std;

int play(string player);
void viewRecord(string, ifstream&);
void record(string, ofstream&, ifstream&, int);
bool name_exists(string, ifstream&);

/* Program - Rock Paper Scissors
* This program allows one to play rockpaper scissors and view their game records.
*/
int main() {
	ifstream view_records;
	ofstream edit_records;

	//open files
	view_records.open("records.txt", ios_base::in);
	edit_records.open("records.txt", ios_base::app);
	//if files will not open
	if (view_records.fail()) cout << "Error!! Records file is not open for viewing.";
	if (edit_records.fail()) cout << "Error!! Records file is not open for editing.";
	

	string player_name;
	//ask for name
	cout << "Welcome to Rock-Paper-Scissors game."<<endl
		<<"Enter you name... ";
	cin>> player_name;

	int i = 1;
	
	cout << endl;
	
	//choice panel
	while (i) {
		int choice;
		cout << "1. Play" << endl
			<< "2. View Record" << endl
			<< "3. Exit" << endl
			<< "Please pick your choice." << endl
			<< "--> ";
		
		cin >> choice;
	
		cout << endl;
	
		switch (choice) {
		case 1: //play a game, record the result
			record(player_name, edit_records, view_records, play(player_name));
			
			break;
	
		case 2: //view record
			viewRecord(player_name, view_records);
			break;
	
		case (3): //if choose to exit, break loop
		default:
			i = 0;
		}
	
		cout << endl;
	}
	
	cout << "Have a nice day, "<<player_name<<". :D";

	//close files
	view_records.close();
	edit_records.close();
}

/* Play(name)
* This function prompts the user to play a game of rock paper scissors. 
* It returns an integer denoting if the player won, lost, or drawed. 
*/
int play(string player) {
	string move;
	RPSMove computer;
	RPSMove player_move;

	cout<< "Computer vs. " << player << "!" << endl
		<< "Pick your move! Rock Paper Scissors"<<endl
		<<"--> ";

	cin >> move;

	//while move is not "rock", "paper", or "scissors", all lowercase
	while (!player_move.validMove(move)) {
		//keep prompting for a move
		cout << "--> ";
		cin >> move;
	}

	player_move = RPSMove(move);

	//print out
	cout << "Computer plays..." << computer<<endl;
	

	switch (player_move.Vs(computer)) {

	case 0: //draw
		cout << "It's a draw! We're Even~";

		return 0; //number denoting "draw"
		break;

	case 1:
		cout << "You win... ;c";
		return 1; //number denoting win
		break;

	case -1:
		cout << "I win!!! Woohooooo! You lost. c:";
		return -1; //number denoting loss
		break;

	default: //error, should never be return of printed.
		cout << "Error...";
		return 1000; 
	}
	
}


/* record (name, edit_records, view_records, result_key)
* This function updates the players' records once they play a game of RPS. 
*/
void record(string name, ofstream& edit_records, ifstream& view_records, int result_key) {
	if (name_exists(name, view_records)) { //If name is already in file
		view_records.seekg(0);

		string temp_string;
		ofstream temp_stream;
		temp_stream.open("temp.txt");

		int counter = 0;
		//print everything in copy file until reach name

		view_records >> temp_string;
		counter++;

		while (temp_string != name) {
			temp_stream << temp_string<<" ";

			if (counter % 4==0) {
				counter /= 4;
				temp_stream << endl;
			}

			view_records >> temp_string;
			counter++;
		}

		//print out name in copy
		temp_stream << temp_string<<" ";

		int temp_num;

		//print out wins in copy file
		view_records >> temp_num;
		if (result_key == 1) temp_stream << ++temp_num << " ";
		else temp_stream << temp_num<<" ";

		//print out lossess in copy file
		view_records >> temp_num;
		if (result_key == -1) temp_stream << ++temp_num << " ";
		else temp_stream << temp_num << " ";

		//print out draws in copy file
		view_records >> temp_num;
		if (result_key == 0) temp_stream << ++temp_num;
		else temp_stream << temp_num;

		cout << endl;

		//print out the rest of the original file in copy
		while (getline(view_records, temp_string)) {
			temp_stream << temp_string << endl;
		}

		//close all files
		temp_stream.close();
		edit_records.close();
		view_records.close();

		//delete original records file, replace it with temp.txt
		//if renaming/deleting did not happen, print out error messages.
		if (remove("records.txt")!=0) 
			cout << "'records.txt' not deleted. Error...\n";
		if (rename("temp.txt", "records.txt") != 0) cout << "'temp.txt' not renamed. Error...\n";

		//reopen streams with new records.
		edit_records.open("records.txt", ios_base::app);
		view_records.open("records.txt", ios_base::in);
	}

	//if name is not in records
	else {
		//add name to end of records
		edit_records << name<<" ";
		
		//add wins, 1/0
		if (result_key == 1) edit_records << 1 << " ";
		else edit_records << 0<<" ";

		//add losses, 1/0
		if (result_key == -1) edit_records << 1 << " ";
		else edit_records << 0 << " ";

		//add draws, 1/0
		if (result_key == 0) edit_records << 1;
		else edit_records << 0;

		edit_records << endl;

	}
}


/* viewRecord(name, view_records)
* This function views the game records and retrieves the player information.
* If the player is not in the records, prints out message. 
*/
void viewRecord(string name, ifstream& records) {
	if (name_exists(name, records)) {
		string temp;

		cout << "Name: " << name << endl;
		records >> temp;
		cout << "# of Wins: " << temp << endl;
		records >> temp;
		cout << "# of Losses: " << temp << endl;
		records >> temp;
		cout << "# of Draws: " << temp << endl;
	}

	else cout<< "You do not have any records yet.";
}


/*name_exists(name, view_records)
* Returns true/false if player is in the records.
* if the player is in the records, move and leave parser after the player name.
* if name is not found, leave parser at the end of the file. 
*/
bool name_exists(string name, ifstream& records) {
	records.seekg(ios_base::beg);
	string temp;

	while ((records >> temp)) {
		if (temp == name) { //if name is found
			return true;
		}

		records >> temp;
		records >> temp;
		records >> temp;
	}

	//reopen file to ensure data is updated
	//position does not get updated.
	records.close();
	records.open("records.txt", ios_base::in);

	return false;
}
