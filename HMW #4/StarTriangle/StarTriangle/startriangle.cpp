/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: startriangle
* Purpose: prints a isosceles triangle of dimensions base: 11, height: 6
*/
#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i <= 5; i++) {
		for (int j = 1; j <= 6+i; j++) { 
			if (6 - i-j <= 0)
			//if (column is a star column)
				cout << "*";			
			else
				cout << " ";
		}
		cout << endl;
	}
}