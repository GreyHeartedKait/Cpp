/*
* Author: Kaitlyn Bui
* Date: 04.28.2021
* Program: Quiz 13-For loop
* Purpose: Computates a running total of a club's membership fees. 
*/
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	double sum=0, membershipCosts=2500;
	cout << fixed << showpoint << setprecision(2)
		<<"Member ship Annual Costs\n\n"
		<<setw(12)<<left<<"Year"<<"Cost($)\n"
		<<"-------------------------\n";

	for (int year = 2020; year <= 2026; year++) {	//Prints out costs for years 2020-2026
		cout << setw(12) << left << year <<"$" <<membershipCosts<<endl;

		sum += membershipCosts; //adds current membership costs to sum
		membershipCosts *= 1.04;//computates next year's membership costs
	}

	cout << "------------------------\n"
		<< right << setw(12) << "sum: $" << sum<<endl<<endl;

	system("pause");
}