/*
* Author: Kaitlyn Bui
* Date: 04.24.2021
* Program: HW3 Days in a Month
* Purpose: Tells user how many days are in a certain month of a certain year.
*/

#include <iostream>

using namespace std;

bool leapYear(int year) {	//tests if a given year is a leap year or not
	if (year % 100 == 0 && year % 400 == 0)
		return true;

	else if (year % 100 != 0 && year % 4 == 0)
		return true;

	else
		return false; 
}

int main() {
	int month, year;

	cout << "Hello user! Welcome to days-in-a-month calculator!"
		<< "\nThis program will ask you to input a number,"
		<< "\n1-12, representing the month and another representing the year.\n\n";

	do {	//user validation loop ensuring that inputted month & year exists
		cout << "\nPlease enter a month and year (ex. 1 2021): ";
		cin >> month >> year;
		
		if (year < 0 || month>12 || month < 1)
			cout << "A year cannot me negative and a month must be in range 1-12.\n";

	} 	while (year < 0 || month>12 || month < 1);

	switch (month) { 
		//all the months with 31 days
		case 7:
		case 10:
		case 12:
		case 5:
		case 8:
		case 3:
		case 1:
			cout << "This month has 31 days.";
			break;
		//all the months with 30 days
		case 4:
		case 6:
		case 9:
		case 11:
			cout << "This month has 30 days.";
			break;
		//Special case for February
		case 2:
			if (leapYear(year))
				cout << "This month has 29 days.";
			else
				cout << "This month has 28 days.";
	}

	cout << endl; 
	system("pause");
}