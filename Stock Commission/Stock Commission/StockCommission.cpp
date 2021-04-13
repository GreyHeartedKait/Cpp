/*
* Author: Kaitlyn Bui
* Date: 04.13.2021
* Program: Stock Commission
* Purpose: Calculate and display the cost of commissioning the stock broker
*/
#include <iostream>
using namespace std;
/*
* var commission: Percent broker receives as commission
* var stock: number of stocks bought
* var price: Cost of each stock
*/
int main() {
	float commission = .02;
	int stock = 750;
	float price = 35;

	cout << "Amount paid for stock: "
		<< stock * price
		<< endl
		<< "Cost of commisioning: "
		<< stock * price * commission
		<< endl
		<< "Total paid: "
		<< stock * price * commission + stock * price; 
}