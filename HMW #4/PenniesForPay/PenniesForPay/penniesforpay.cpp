/*
* Author: Kaitlyn
* Date: 05.11.2021
* Program: penniesforpay
* Purpose: generates a summary wage table
*/

#include <iostream>
#include <iomanip>

using namespace std;

/*
* Name: days()
* Purpose: Accepts and validates an integer number of days
*/
int days();

/*
* name: line()
* purpose: prints a line
*/
void line();

int main() {
	int numOfDays;
	double totalpay=0, salary=.01;	//salary & totalpay are in dollars
	cout << left<<fixed<<setprecision(2)<<showpoint
		<<"Hello user! Welcome to the wage-table generator.\n"
		<<"Please enter the number of days you are working to a table of daily salaries \n"
		<<"and your total wage.\n\n";

	numOfDays = days();
	cout << endl<<setw(6)<<"day #"<<"| daily salary"<<endl;
	line();
	for (int i = 1; i <= numOfDays; i++) {
		cout << endl<<setw(6) << i << "| $" << salary;
		totalpay += salary;
		salary *= 2;
	}
	cout << endl;
	line();
	cout << endl<<setw(6)<<"Total"<<"| $"<<totalpay<<endl<<endl;

	system("pause");
}

int days() {
	int days;
	cout << "Please enter a number of days: ";
	cin >> days;

	while (days<=0) {
		cout << endl << "Please input a number of days greater than 0.\n"
			<< "Number of days: ";
		cin >> days;
	}

	return days;

}

void line() {
	cout << "---------------------------";
}
