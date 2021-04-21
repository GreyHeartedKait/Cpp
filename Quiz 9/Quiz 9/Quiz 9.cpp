/*
* Author: Kaitlyn Bui
* Date: 04.20.2021
* Program: Quiz 9- The color mixer
* Purpose: Mixes two primary colors together and ouputs the resulting secondary color.
*/

#include <iostream>

using namespace std;

/*
* Purpose: 'Mixes' two colors and returns appropriate secondary or primary color. 
* 
*/
string colorMixer(string c1, string c2) {
	if (c1 == c2) {
		return c2;
	}

	else if ((c1 == "blue" | c2 == "blue") & (c1 == "red" | c2 == "red")) {
		return "purple";
	}
	else if ((c1 == "yellow" | c2 == "yellow") & (c1 == "red" | c2 == "red")) {
		return "orange";
	}

	else {
		return "green";
	}
}


int main() {
	string one, two;
	cout << "Hello user! Welcome to the color mixer. Imput two primary colors and\n"
		<< "find out what secondary color they make!\n"
		<< "Let us start!"
		<< "\n\nInput your first color: ";
	cin >> one;
	cout << "Second color: ";
	cin >> two;
	
	if ((one == "red" | one == "blue" | one == "yellow") & (one == "red" | one == "blue" | one == "yellow")) {
		cout<<"\nThe resulting color is: "<<colorMixer(one,two)<<endl;
	}

	else {
		cout << "Please input red, blue, or yellow (no caps) and try again. Thank you!\n";
	}

	system("pause");
}