/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Monthly Sales Tax
* Purpose: Outputs a sales tax report
*/
#include <iostream>
#include<iomanip>

using namespace std;

/*
* Purpose: Draws line.
*/
void line() {
	cout << "-------------------------------";
}

int main() {
	/*
	* var string month: Given month
	* var string year: given year
	* var double totalAmount: the total amount of money earned
	* var double sales: the total sales earned
	* const double STATE_SALES_TAX: the state's sales tax
	* const double COUNTY_SALES_TAX: The county's sales tax
	*/
	string month, year;
	double totalAmount, sales;
	const double STATE_SALES_TAX = .04;
	const double COUNTY_SALES_TAX = .02;
	
	cout <<left<<fixed<<setprecision(2)
		<<"Hello user. Welcome to the sales tax report maker. Please enter in the below values.\n"
		<< "Month Year: ";
	cin >> month>> year;
	cout << "Total amount collected: ";
	cin >> totalAmount;
	sales = totalAmount / 1.06; //removes sales tax from total collected

	cout << endl<<month<<", "<<year<<endl;
	line();
	cout << endl << setw(20) << "Total Collected" << right << "$" << setw(10) << totalAmount
		<< endl << left << setw(20) << "Sales" << right << "$" << setw(10) << sales
		<< endl << left << setw(20) << "County Sales Tax" << right << "$" << setw(10) << sales * COUNTY_SALES_TAX
		<< endl << left << setw(20) << "State Sales Tax" << right << "$" << setw(10) << sales * STATE_SALES_TAX
		<< endl << left << setw(20) << "Total Sales Tax" << right << "$" << setw(10) 
		<< sales * (COUNTY_SALES_TAX + STATE_SALES_TAX)
		<< endl;
	line();
	cout << endl << endl;

	system("pause");



}