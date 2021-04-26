/*
* Author: Kaitlyn Bui
* Date: 04.26.2021
* Program: Exam 1 programming challenge 
* Purpose: Calculates a phone bill based on call start-time & length of call.
*/

#include <iostream>
#include <iomanip>
using namespace std;

float phoneBill(int minutes, float time) {				//Takes start-time, minutes, and phone rates to output bill
	if (time >= 0 && time <= 6.59)
		return.1 * minutes;
	else if (time >= 7 && time <= 19)
		return minutes * .45;
	else
		return .3 * minutes; 
}

int main() {
	float time;
	int minutes; 
	cout << "Hello user! Welcome to the long-distance phone bill!\n";

	do{		//user validation loop: conditions- minutes is positive & time is an actual time
		cout << "\n\nPlease enter in the time your call started (HH.MM): ";
		cin >> time;

		cout << "\nPlease enter in the length of your call (in minutes): ";
		cin >> minutes;

		if (time >= 23.60 || time < 0|| (time - static_cast<int>(time))>=.60) {
			cout << "Please enter an actual time.\n";
		}

		if (minutes < 0) {
			cout << "Please enter a positive number of minutes.\n";
		}

	} while (time>=23.60 || time<0|| (time - static_cast<int>(time))>=.6||minutes<0);

	cout << fixed << setprecision(2) << showpoint << "\nYour bill is $" << phoneBill(minutes, time)<<"."<<endl<<endl;

	system("pause");
}