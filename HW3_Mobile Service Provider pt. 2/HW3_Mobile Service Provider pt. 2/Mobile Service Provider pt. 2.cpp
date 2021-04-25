/*
* Author: Kaitlyn Bui
* Date: 04.24.2021
* Program: HW3_Mobile Service Provider pt. 2
* Purpose: Calculates user's savings from using different plans
*/

#include <iostream>
#include <iomanip>
using namespace std;

double package(char choice, int minutes) {				//Calculates bill for all plans
	if (choice == 'A') {
		minutes = minutes <= 450 ? 0 : minutes - 450;
		return 39.99 + minutes * .45;
	}

	else if (choice == 'B') {
		minutes = minutes <= 900 ? 0 : minutes - 900;
		return 59.99 + minutes * .40;
	}

	else
		return 69.99;
}

int main() {
	int minutes, foo=0;			//foo is used to determine whether or not
	char choice;				//"no available savings" prints

	//instructions
	cout << fixed << showpoint << setprecision(2)
		<< "Hello user! Welcome to your phone bill savings calculator.\n"
		<< "Please input the following to find out how much you can save by switching plans.\n\n";

	do {				//user validation loop: checks if choice is 'A', 'B', or 'C'
		cout << "Current Package (A, B, or C): ";
		cin >> choice;

		cout << "\nMinutes used: ";
		cin >> minutes;

		//error messages corresponding with while-loop continuation 
		if (choice != 'A' && choice != 'B' && choice != 'c')
			cout << "\nPlease choose option A, B, or C\n\n";
		if (minutes < 0)
			cout << "Please input a positive number of minutes.\n\n";
	} while ((choice != 'A' && choice != 'B' && choice != 'C') || minutes < 0);

	for (int i = 0; i <= 2; i++) {		//Prints out a message if a plan saves the user money
		if ((package(choice, minutes) - package('A' + i, minutes))>0) {
			cout << "\nChoice " << (char)('A' + i) << " will save you $"
				<< package(choice, minutes) - package('A' + i, minutes)
				<< " every month.";
			foo++;	//counts how many plans the user can save money from using
		}
	}
	if (foo == 0) //is the user cannot save money by switching to any plans
		cout << "You will save no money by switching to other plans.";
	cout <<".\n\n";

	system("pause");


}