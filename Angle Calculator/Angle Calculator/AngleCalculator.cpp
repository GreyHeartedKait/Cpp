/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Angle Calculator
* Purpose: Input an angle, receive the cos, sin, and tan of the angle
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	/*
	* var float angle: the angle provided, in radians 
	*/
	float angle;
	cout << fixed << setprecision(4)
		<< "Hello user! Welcome to the angle calculator.\n"
		<< "Please input an angle (rads): ";
	cin >> angle;

	cout << "\nTangent: " << tan(angle) << endl
		<< "Sine: " << sin(angle) << endl
		<< "Cosine: " << cos(angle)<<endl<<endl;

	system("pause");
}