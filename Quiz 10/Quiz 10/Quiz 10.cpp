/*
* Author: Kaitlyn Bui
* Date: 04.22.2021
* Program: Quiz 10-Geometry Calculator
* Purpose: Calculates the area, perimeter, or both, of a rectangle.
*/
#include <iostream>

using namespace std;

int main() {
	float length, width;
	char choice; 
	//intro + instructions
	cout << "Hello user. Welcome to the geometry-of-a-rectangle calculator!"
		<< "\nPlease enter the length and width of the rectangle.\n"
		<< "\nWidth: ";

	cin >> width;

	cout << "Length: ";

	cin >> length;

	//'menu'
	cout << "\nPlease input an option below.\n"
		<< "A. Area"
		<< "\nB. Perimeter\n"
		<< "C. Both"
		<< "\n\nYour Choice: ";

	cin >> choice;


	switch (choice) {
		case 'C': 
			cout << "Here are both the perimeter and area:\n"
				<< "Area: " << length * width << endl;
		case 'B': cout << "\nPerimeter: " << length *2 + 2* width << endl;
			break;
		case 'A': 
			cout<<"\nArea: " << length * width << endl;
			break;
		default:
			cout << "Please try again. You did not enter A, B, or C.\n";
	}

	system("pause");
}