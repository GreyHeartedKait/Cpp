/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: squaredisplays
* Purpose:
*/

#include <iostream>

using namespace std;
/*
* name: sidelength()
* purpose: Accepts and validates a sidelength input
*/
int sidelength();

/*
* Name: copy()
* purpose: accepts a base string and integer. Returns string "base_string"*integer
*/
string copy(string, int);

int main() {
	int side;
	string foo;

	cout << "Hello user! Welcome to the square printer. Please input the side length you want.\n\n";

	side = sidelength();
	foo = copy("X", side);
	cout << endl;


	for (int i = 1; i <= side; i++) {
		cout << foo<<endl;
	}

	cout << endl << endl;
	system("pause");
}

int sidelength() {
	int foo;
	cout << "Please enter an integer length: ";
	cin >> foo;

	while (foo <= 0 || foo>15) {
		cout << endl << "Please input a integer greater than 0 and less than 16.\n"
			<< "Side Length: ";
		cin >> foo;
	}

	return foo;

}

string copy(string base, int n) {
	string foo="";
	for (int i = 1; i <= n; i++) {
		foo += base;
	}
	return foo; 
}
