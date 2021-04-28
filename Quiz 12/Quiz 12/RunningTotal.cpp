/*
* Author: Kaitlyn Bui
* Date: 04.27.2021
* Program: Quiz 12-Running Total
* Purpose: Takes running total of employee pay and taxes.
*/
#include <iostream>
#include <iomanip>
using namespace std;

double netPay(double pay, double state_tax, double fed_tax) {	//calculates net pay
	return pay - state_tax - fed_tax;
}



int main() {
	int ID;
	double grossPay, stateTax, federalTax, totalGrossPay=0, totalStateTax=0, totalFederalTax=0;

	cout << fixed << showpoint << setprecision(2)
		<< "Welcome to the running total program! Below, the user will enter employees' IDs\n"
		<< "and pay info to receive the running total.\n"
		<< "\nWhen the user has typed in all employees, type in 0 in the employee ID field.\n"; 
		
	
	while (true) {	//infinite loop and breaks when ID==0
		cout << "\nPlease type in employee ID: ";
		cin >> ID;
		while ((ID < 100 || ID>999) && ID != 0) {
		
			cout <<"\nError: Given ID is invalid.\n"
				<<"Please type in employee ID: ";
			cin >> ID; 


		} 

		if (ID == 0)
			break;
		else {
			cout << "Gross pay: $";
			cin >> grossPay;
			cout << "State Tax: $";
			cin >> stateTax;
			cout << "Federal Tax: $";
			cin >> federalTax;

			while (grossPay < 0 || federalTax < 0 || stateTax < 0 || (federalTax + stateTax) >= grossPay){
				cout << "Error: No values can be negative and taxes cannot be higher than gross pay.\n\n";
				cout << "Gross pay: $";
				cin >> grossPay;
				cout << "State Tax: $";
				cin >> stateTax;
				cout << "Federal Tax: $";
				cin >> federalTax;
			}

			totalGrossPay += grossPay;	//adds the employee's info into running total
			totalStateTax += stateTax;
			totalFederalTax += federalTax;
		}
	}
	
	cout << "\nTotals\n"
		<< "--------------------\n"
		<< "Total Gross pay: $" << totalGrossPay
		<< "\nTotal State Tax: $" << totalStateTax
		<< "\nTotal Federal Tax: $" << totalFederalTax
		<< "\nTotal net pay: $" << netPay(totalGrossPay, totalStateTax, totalFederalTax) << endl << endl;;

	system("pause");

}
