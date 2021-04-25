/*
* Author: Kaitlyn Bui
* Date: 04.24.2021
* Program: Software Sales
* Purpose: Calculates the total cost of a software purchase, including discounts. 
*/
#include <iostream>

using namespace std;

int main() {
	int quantity;				
	const double MINOR_DISCOUNT = .8;	//discount percent =100(1-listedDiscount)%
	const double SECONDARY_DISCOUNT = .7;
	const double BIG_DISCOUNT = .6;
	const double BEST_DISCOUNT = .5;
	const double PRICE = 99;

	cout << "Welcome to the bulk-discount calculator!\n"
		<< "Please enter the quantity of software you are purchasing\n"
		<< "to receive the total order cost.\n\n";

	do {		//user-validation loop: no negative quantities of software 
		cout<<"Quantity of software: ";
		cin >> quantity;

		if (quantity < 0) {
			cout<<"You cannot buy negative software.\n"
		}

	} 	while (quantity < 0);

	cout << "\nTotal Order cost: $";

	//calculating total costs 

	if (quantity >= 10 && quantity <= 19)
		cout << quantity * MINOR_DISCOUNT * PRICE;
	else if (quantity >= 20 && quantity <= 49)
		cout << quantity * SECONDARY_DISCOUNT * PRICE;
	else if (quantity >= 50 && quantity <= 99)
		cout << quantity * BIG_DISCOUNT * PRICE;
	else if (quantity >= 100)
		cout << quantity * BEST_DISCOUNT * PRICE;

	else
		cout << quantity * PRICE;

	cout << endl << endl;

	system("pause");

}