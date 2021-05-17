/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: population bar chart
* Purpose: Read file and create table using given information
*/
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int pop, year=1900; //stands for population
	ifstream population("C:\\Users\\User\\source\\repos\\C-\\HMW #4\\People.txt");
	cout << "Prairieville Population Growth\n"
		<< "------------------------------\n";

	while (population >> pop) {
		cout << year<<" ";
		for (int i = round(1.0*pop / 1000); i > 0; i--) {
			cout << "*";
		}
		cout << endl;
		year += 20;
	}

	population.close(); 

	system("pause");
}