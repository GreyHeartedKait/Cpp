/*
* Author: Kaitlyn Bui
* Date: 05.06.2021
* Program: getRoots
* Purpose: Calculate the quadratic formula
*/
#include <iostream>
#include <cmath>
using namespace std;

void getroots(double, double, double); //Function prototype

int main() {
	double a, b, c;
	cout << "Hello user! Welcome to the quadratic formula calculator!\n"
		<< "Quadratic Equation: ax^2+bx+c\n"
		<< "Please enter a b c: ";
	cin >> a;
	cin >> b;
	cin >> c;

	getroots(a, b, c);

	system("pause");
}
/*
* Function: getroots
* Purpose: calculate and display the roots of a function
*/
void getroots(double a, double b, double c) {
	double determinent = pow(b, 2) - (4 * a * c); //determinent = b^2 -4ac

	if (a == 0 && b != 0) 
		cout << "The root is " << -c / b<<" \n"; //the root is -c/b

	else if (determinent < 0 || a==c==b==0) {
		cout << "There is no real root.\n";
	}

	else {
		cout << "There are two roots: " << (-1*b + pow(determinent, .5)) / (2 * a) << ", " << (1*-b - pow(determinent, .5)) / (2 * a)
			<< ".\n\n"; //quadratic formula = (-b +/- sqrt(determinent)/2a
	}
}