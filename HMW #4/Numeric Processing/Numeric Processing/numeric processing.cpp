/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: numeric processing
* Purpose: Reads a file containing numbers and outputs # of nums., avg. num. value, and sum of all numbers. 
*/
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	int nums=0, sum=0, foo;
	ifstream numbers("C:\\Users\\User\\source\\repos\\C-\\HMW #4\\random.txt");

	while (numbers >> foo) {
		sum += foo;
		nums++;
	}

	cout << "There are " << nums << " numbers in this file.\n"
		<<"Each number is on average "<<1.0*sum/nums<<".\n"
		<<"The total sum is "<<sum<<".\n\n";

	numbers.close();

	system("pause");
	
}