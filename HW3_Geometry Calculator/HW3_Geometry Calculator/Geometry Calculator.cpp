/*
* Author: Kaitlyn Bui
* Date: 04.24.2021
* Program: HW3 Geometry Calculator
* Purpose: Displays a menu of areas user can choose from 
* and calculates the chosen option.
*/

#include <iostream>
#include <iomanip>

using namespace std;

double areaCircle(double radius) {					//calculates area of a circle
	return radius * radius * 3.14159;
}

double areaRectangle(double length, double width) {	//calculates area of a rectangle
	return length * width;
}

double areaTriangle(double height, double base) {	//calculates area of a triangle
	return height * base * .5; 
}

int main() {
	int choice; 
	double d1=0, d2=0;

	cout << fixed << setprecision(2) << noshowpoint
		<< "Hello user! Welcome to the geometry calculator.\n"
		<< "Please pick from the below options: \n\n"		//menu
		<< "1. Calculate the Area of a Circle\n"
		<< "2. Calculate the Area of a Rectangle\n"
		<< "3. Calculate the Area of a Triangle\n"
		<< "4. Quit\n";

	//picking option

	do {//user validation loop to ensure choice is valid
		cout<< "\nYour choice: ";
		cin >> choice;

		if (choice > 4 || choice < 1)
			cout <<"Please choose a valid option.\n";

	} while (choice > 4 || choice < 1);

	//asking for measurements

	do {//user validation loop to ensure inputted measurements are valid
		switch (choice) {
		case 3:
			//using ambiguity and fall through to print instructions for both
			//options 2 & 3 (rectangle & triangle)

		case 2:
			cout << "Please enter the length and height (ex. 5 4): ";
			cin >> d1 >> d2;
			break;
		case 1:
			cout << "\nPlease enter the radius of the circle: ";
			cin >> d1;
			break;
		case 4:
			cout << "Understood. Thank you.\n";
			break;
		}
		if (d2 < 0 || d1 < 0)//error message explaining continuation of while loop
			cout << "Please try again. Measurements cannot be negative.\n\n";
	} while (d2 < 0 || d1 < 0);//d1 & d2 are by default equal to 0. 

	//outputing areas

	if (choice == 1) {
		cout << "\nThe area of this circle is: " << areaCircle(d1) << ".\n";
	}
	else if (choice == 2) {
		cout << "\nThe area of the rectangle is " << areaRectangle(d1, d2) << ".\n";
	}

	else if (choice == 3) {
		cout << "\nThe area of the triangle is " << areaTriangle(d1, d2)<<".\n";
	}

	cout << endl;

	system("pause");
}