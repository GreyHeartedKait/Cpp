/*
* Author: Kaitlyn Bui
* Date: 04.30.2021
* Program: rainfall stats
* Purpose: Calculate rainfall over a given number of years
*/
/*#include <iostream>
using namespace std;

int main() {
	int years;				//given number of years
	double rainfall;		//rainfall/month
	double rainfallSum=0;	//total rainfall over given number of years

	//intro & info
	cout << "Hello user! Welcome to the annual rainfall calculator.\n\n"
		<< "Please enter the number of years you wish to calculate the rainfall for.\n"
		<< "# of Years: ";
	cin >> years;

	while (years < 1) {	//user validation loop: years must not be 0 or negative
		cout << "\nPlease input a valid number of years.\n"
			<< "# of Years: ";

		cin >> years;
	}

	for (int i = 1; i <= years; i++) {	//Asks for rainfall/per month over given number
		for (int j = 1; j <= 12; j++) {	//of years
			cout << "\nYear "<<i<<", Month " << j << endl
				<< "Amount of rainfall: ";
			cin >> rainfall;
			
			while (rainfall < 0) {	//input validation loop: rainfall/month non-negative
				cout << "\nPlease input a non-negative amount of rainfall.\n"
					<< "Rainfall: ";

				cin >> rainfall;
			}

			rainfallSum += rainfall;
			
		}
	}
	//print info sentance 
	cout << "Total rainfall for " << years << " is " << rainfallSum<<".\n\n";

	system("pause");
}	*/
