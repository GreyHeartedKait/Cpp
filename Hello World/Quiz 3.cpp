/*
* Author: Kaitlyn Bui
* Date: 04.12.2021
* Program: Quiz 3
* Purpose: The program should play a word game with the user.
*/
#include <iostream>
using namespace std;

int convertMinToSec(int minutes) {
	return minutes * 60;
}

int main(){
	string name, age, city, college, job;
	cout << "Hello user! Please input details according to the prompt." << endl;
	cout << "Your name: ";
	cin >> name;
	cout << endl; 
	cout << "Your age: ";
	cin >> age;
	cout << endl;
	cout << "Name of a city: ";
	cin >> city;
	cout << endl;
	cout << "Name of a college: ";
	cin >> college;
	cout << endl;
	cout << "Name of a profession: ";
	cin >> job;
	cout << endl;
}