/*
* Author: Kaitlyn Bui
* Date: 05.31.2021
* Program: account number validation
* Purpose: Checks if account number is valid
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool IIV(long, long[], int);	//Integer Input Validation, code rewrite of CIV

int main() {
	int const SIZE = 18;
	long account_numbers[SIZE] = {5658845, 4520125, 7895122, 8777541,8451277,1302850,8080152,4562555,5552012,5050552,7825877,1250255,
								  1005231,6545231,3852085,7576651,7881200,4581002};
	long account;
	//Input
	cout << "Hello user! Please enter your charge account number to find out if it is valid."
		<< "\nCharge Account Number: ";
	cin >> account;

	cout << endl;
	if (IIV(account, account_numbers, SIZE))	//if acc. number is in above list
		cout << "Account number is valid.";
	else {										//if acc. number is not in above list, 
		cout << "Account number is invalid.";
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

/*
* Function: IIV or Integer Input Validation
* Purpose: Checks if input is Valid
*/
bool IIV(long input, long allowed[], int size) {	
	sort(allowed, allowed + size);
	return binary_search(allowed, allowed + size, input);
}