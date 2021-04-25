/*
* Author: Kaitlyn Bui
* Date: 04.24.2021
* Program: HW3 Bank Charges
* Purpose: Calculates a banks service fee given a users balance
* & # number of written checks
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int numChecks;
	double balance, fees=0;

	cout << "Hello user!\n"
		<< "Please enter your current balance and the # of checks written: \n"
		<< "\nBalance: ";

	cin >> balance;

	if (balance < 400)		//aditional fee for a balance lower than 400.
		fees += 15; 
	if (balance < 0)		//Overdrawn message is balance is negative 
		cout << "\nURGENT: Your account is overdrawn.\n\n";
	

	do {	//user validation loop, checks if var numChecks is negative
		cout << "Number of checks written: ";
		cin >> numChecks;

		if (numChecks < 0)
			cout << "You cannot write a negative amount of checks. Please try again.\n\n";
	}
	while (numChecks<0);

	//fee calculations

	if (numChecks < 20)
		fees += (.1 * numChecks);


	else if (numChecks >= 20 && numChecks <= 39)
		fees += (.08*numChecks);

	else if (numChecks >= 40 && numChecks <= 59)
		fees += (.06 * numChecks);

	else
		fees += (.08 * numChecks);

	//Printing service fee 

	cout <<fixed<<setprecision(2)<<showpoint
		<<"The monthly service fee is $" << fees << endl<<endl;

	system("pause");
}