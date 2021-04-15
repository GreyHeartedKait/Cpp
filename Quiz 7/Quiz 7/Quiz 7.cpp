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
	if (input == password) {
		cout << "Congratulations!Access granted!\n"
			<< "You will be directed to the homepage shortly...\n";
	}
	else {
		cout<< "Sorry, wrong code.\n"

			<< "Access denied.\n"

			<< "Please try again.\n";
	}

	system("pause");
}