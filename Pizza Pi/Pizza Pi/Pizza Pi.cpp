/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Pizza Pi
* Purpose: Calculates the number of slices a pizza can have.
*/
#include<cmath>
#include <iostream>

using namespace std;

int main() {
	/*
	* var double diameter: the diameter of the pizza
	* var double area: the area of the pizza
	* const double PI: the value pi
	* const double SLIVE_SIZE: the area of each slice 
	*/
	const double PI = 3.1415926535897932384626433832795028841;
	const double SLICE_SIZE = 14.125;
	double diameter, area;

	cout << "Hello user. Welcome to the pizza slice calculator,"
		<< "guaranteed to tell the exact # of slices/pie.\n"
		<< "Please input the diameter of the pizza(inches): ";
	cin >> diameter;

	area = pow(diameter / 2, 2) * PI;

	cout << "This pizza has " << round(area / SLICE_SIZE)<<" slices.\n";

	system("pause");
}
