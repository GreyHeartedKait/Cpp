/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Ingredient Adjuster
* Purpose: Asks how many coolies the user would like and produces a recipe. 
*/

#include <iostream>
#include <iomanip>

using namespace std;

/*
* Purpose: Draws line.
*/
void line() {
	cout << "--------------------------------";
}

int main() {
	double sugar = 5 / 48.0, butter = 1 / 48.0, flour = 75 / 48.0;
	int amtCookies;
	cout << fixed << setprecision(2)<<left
		<< "Hello user. How many cookies would you like to make? ";
	cin >> amtCookies;
	cout << endl << "Recipe for "<<amtCookies<<" cookies\n";
	line();
	cout << endl << setw(10) << "Sugar" << setw(6)<<sugar * amtCookies<<" cups"
		<< endl << setw(10) << "Butter" << setw(6)<<butter * amtCookies<<" cups"
		<< endl << setw(10) << "Flour" << setw(6)<<flour * amtCookies<<" cups\n";

	line();
	cout << endl;

	system("pause");
}
