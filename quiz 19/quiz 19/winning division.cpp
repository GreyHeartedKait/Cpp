/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: winning division
* Purpose: calculates and displays the division with the highest sales. 
*/
#include <iostream>

using namespace std;

/*
* Name: getSales()
* purpose: receives and validates the quarterly sales of a division
*/
double getSales(string);

/*
* Name: findHighest()
* Purpose: computes and displays the division with the highest quarterly sales. 
*/
void findHighest(double, double, double, double);

int main() {
	double NE, SE, NW, SW;
	cout << "Hello user! Welcome to the division competition calculator!\n"
		<< "This program will display the division with the highest sales!\n";

	NE = getSales("NorthEast"),
	SE = getSales("SouthEast"),
	NW = getSales("NorthWest"),
	SW = getSales("SouthWest");

	findHighest(NE, SE, NW, SW);

	cout << endl;
	system("pause");
	return 0;
}

void findHighest(double div1, double div2, double div3, double div4) {
	string div;
	double highest;

	if (div1 > div2 && div1 > div3 && div1 > div4) {
		div = "NE";
		highest = div1; 
	}
	else if (div2 > div1 && div2 > div3 && div2 > div4) {
		div = "SE";
		highest = div2;
	}
	else if (div3 > div1 && div3 > div2 && div3 > div4) {
		div = "NW";
		highest = div3; 
	}

	else {
		div = "SW";
		highest = div4;
	}

	cout << "The division with the highest sales is " << div << " with a quarterly sales of $"<<highest<<".\n";
}


double getSales(string div){
	double sales;
	cout << endl << "What is the " << div << "'s quarterly sales? ";
	cin >> sales;

	while (sales < 0 ) {
		cout << "Try again. Please enter a non-negative number with a decimal in the hundredths.\n"
			<< "Quarterly sales: ";
		cin >> sales;
	}

	return sales;
}


