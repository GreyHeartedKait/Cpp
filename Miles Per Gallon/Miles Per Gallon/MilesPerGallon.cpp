/*
* Author: Kaitlyn Bui
* Date: 04.13.2021
* Program: MilesPerGallon
* Purpose: Calculates the miles per gallon a car can drive
*/
#include <iostream>
using namespace std;
/*
* Var miles: # of miles the car drove.
* Var gals: # of gallons of gasoline the car had.
* Purpose: Calculates the miles per gallon of gas. 
*/

float mPG(int miles, int gals){
	return miles / gals;
}

int main() {
	cout << mPG(375, 15);
	system("pause");
}