/*
* Author: Kaitlyn Bui
* Date: 04.13.2021
* Program: Total Purchase
* Purpose: Calculate the total price of 5 items, with tax.
*/

#include <iostream>
using namespace std;

int main() {
	/*
	* var item1: cost of item 1
	* var item2: cost of item 2
	* var item3: cost of item 3
	* var item4: cost of item 4
	* var item5: cost of item 5
	* var subtotal: cost of all items
	* const var sales_Tax: sales tax
	*/
	float item1 = 15.95,
		item2 = 24.95,
		item3 = 6.95,
		item4 = 12.95,
		item5 = 3.95,
		subtotal = item1 + item2 + item3 + item4 + item5;
	const float sales_Tax = .07;

	cout << "item 1: $" << item1
		<< "\nitem 2: $" << item2
		<< "\nitem 3: $" << item3
		<< "\nitem 4: $" << item4
		<< "\nitem 5: $" << item5
		<< "\nSubtotal: $" << subtotal
		<< "\nSales tax: $" << subtotal * sales_Tax
		<< "\nTotal: $" << subtotal * sales_Tax + subtotal; 
	system("pause");
}		