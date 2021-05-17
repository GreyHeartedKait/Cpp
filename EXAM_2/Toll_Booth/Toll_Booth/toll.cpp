/*
* Author: Kaitlyn Bui
* Date: 05.17.2021
* Program: toll
* Purpose: Asks for necessary information and calculates a toll. 
*/

#include <iostream>
#include <iomanip>

using namespace std;

double CalcToll(int, bool, bool);	//function prototype

int main() {
	int hour;	//hour of the day
	char day, weekend;	//whether time is AM/PM & whether day is a weekend or not


	cout <<fixed<<setprecision(2)<<showpoint	//prompt
		<<"Hello user! Welcome to our toll booth.\n"
		<< "Please enter the current hour (non-military time): ";

	cin >> hour; 

	while (hour <= 0 || hour > 12) {	//time validation
		cout << "\nPlease enter a valid time (from 1 to 12): ";
		cin >> hour; 
	}

	cout << "\nIs it AM or PM (enter a for AM and p for PM)? ";
	cin >> day;

	while (day != 'a' && day != 'p') {	//validation loop
		cout << "\nPlease enter a or p: ";
		cin >> day;
	}


	cout << "\nIs it a weekend(n or y)? ";
	cin >> weekend;

	while (weekend != 'n' && weekend != 'y') {	//validation loop
		cout << "\nPlease enter n or y: ";
		cin >> weekend;
	}
	
	cout << "Your toll is $" << CalcToll(hour, (day == 'a'), (weekend == 'y')) << ".\n\n";	//display toll

	system("pause");

	


}

double CalcToll(int hour, bool day, bool weekend) {
	if (weekend) {	//week end
		if (hour < 7 && day)	//before 7 AM
			return 1.05;
		else if (hour >= 8 && !day)	//after 8 PM and before midnight
			return 1.1;
		else
			return 2.15;	//from 7AM and 8PM
	}

	else {	//week day
		if (hour < 7 && day)					//before 7 AM
			return 1.15;
		else if (hour >= 7 && hour <= 9 && day)	//from 7 AM to before 10 AM
			return 2.95;
		else if (hour >= 3 && hour <= 7 && !day)	//From 3 PM to before 8 PM
			return 3.95;
		else if (hour >= 8 && !day)				//from 8 PM and before midnight
			return 1.4;
		else
			return 1.9;							//from 10 am and before 3 pm.
	}

}