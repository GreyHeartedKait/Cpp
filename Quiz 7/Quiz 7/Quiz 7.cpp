/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Quiz 7
* Purpose: Asks for password and compares to the preset password.
*/
#include <iostream>
using namespace std;

int main() {
	/*
	* var password: Preset password
	* var input: entered password
	*/
	string password = "HelloFromTheOtherSide", input;
	cout << "Hello user. Welcome to security gate.\n\n"
		<< "Please enter you password: ";
	cin >> input; 
	if (input == password)
		cout << "Access granted. Welcome in!\n";

	else
		cout << "Access denied. Try again.\n";

	system("pause");
}