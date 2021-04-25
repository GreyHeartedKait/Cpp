/*
* Author: Kaitlyn Bui
* Date: 04.24.2021
* Program: HW3_Mobile Service Provider
* Purpose: Calculates user's phone bill based on cellphone plan.
*/

#include <iostream>
#include <iomanip>
using namespace std;

double pA(int minutes) {							//Calculates bill for plan A
	minutes = minutes <= 450 ? 0 : minutes - 450;
	return 39.99+minutes*.45;
}

double pB(int minutes) {							//Calculates bill for plan B
	minutes = minutes <= 900 ? 0 : minutes - 900;
	return 59.99 + minutes * .4;
}

double pC(int minutes) {							//Calculates bill for plan C
	return 69.99;
}

int main() {
	int minutes;
	char choice;

	//instructions
	cout <<fixed<<showpoint<< setprecision(2)
		<<"Hello user! Welcome to your phone bill.\n"
		<< "Please input the following information to receive your phone bill.\n\n";
	
	do {				//user validation loop: checks if choice is 'A', 'B', or 'C'
		cout << "Package (A, B, or C): ";
		cin >> choice;

		cout << "\nMinutes used: ";
		cin >> minutes;

		//error messages corresponding with while-loop continuation 
		if (choice != 'A' && choice != 'B' && choice != 'c')
			cout << "\nPlease choose option A, B, or C\n\n";
		if (minutes < 0)
			cout << "Please input a positive number of minutes.\n\n";
	} while ((choice != 'A' && choice != 'B' && choice != 'C') || minutes<0);

	//print out phone bill
	cout << "\nYour phone bill this month is $";
	
	switch (choice) {
		case 'A':
			cout << pA(minutes);
			break;
		case 'B':
			cout << pB(minutes);
			break;
		case 'C':
			cout << pC(minutes);
	}
	
	cout << ".\n\n";

	system("pause");
	

}