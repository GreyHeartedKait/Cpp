/*
* Author: Kaitlyn Bui
* Date: 04.12.2021
* Program: Quiz 4
* Purpose: The program will play a word game with the user.
*/

#include <string>
#include <iostream>
using namespace std;

unsigned long long convertYearsToSec(int years){
	return years *365.25*24*60*60;
}

int main() {
	string name, job, college, city;
	int age;

	cout << "Hello user! Welcome to the quiz 4 word game, I am honored to be your host.\n"
		<< "Please follow the prompts and enter in the appropriate information.\n\n";
	system("pause");
	cout << endl
		<< "What is the user's name? \n";
	getline(cin, name);
	cout << endl
		<< "How old is [" + name + "]? \n";
	cin>> age;
	cout << endl;
	
	cout<< "Name a city: \n";
	getline(cin, city); //Reader starts reading the line directly after the age variable. To counteract that,
	//this line "wastes" it, 
	getline(cin, city);
	cout << endl
		<< "Name a college: \n";
	getline(cin, college);
	cout << endl
		<< "Name a profession: \n";
	getline(cin, job);


	cout << endl
		<< "There once was a user named "
		<< "[" + name + "]"
		<< " who lived in "
		<< city
		<< ". At the age of "
		<< age
		<< " [" + name + "] went to college at "
		<< college
		<< ". [" + name + "] graduated and went to work as a "
		<< job + ".\n\n"
		<< "[" + name + "], if expressed in seconds, the user is already "
		<< convertYearsToSec(age)<<" seconds old!\n\n";

	system("pause");
	

}