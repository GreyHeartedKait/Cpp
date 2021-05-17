/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: winning division pt. 2
* Purpose: calculates and displays the division with the highest sales.
*/
#include <iostream>

using namespace std;

/*
* Name: getSales()
* purpose: receives and validates the quarterly sales of a division
*/
void getSales(double&, string);

/*
* Name: findHighest()
* Purpose: computes and displays the division with the highest quarterly sales.
*/
void findHighest(double, string, double&, string&);

int main() {
	double NE, SE, NW, SW, highest;
	string highdiv; 
	cout << "Hello user! Welcome to the division competition calculator!\n"
		<< "This program will display the division with the highest sales!\n";

	getSales(NE,"NorthEast");
	getSales(SE, "SouthEast");
	getSales(NW, "NorthWest"),
	getSales(SW, "SouthWest");

	highdiv = "NorthEast";
	highest = NE; 

	findHighest(SE,"SouthEast",highest, highdiv);
	findHighest(NW, "NorthWest", highest, highdiv);
	findHighest(SW, "SouthWest", highest, highdiv);

	cout << "\nThe divison with the highest sales is " << highdiv<<" with a quarterly sales of $"<<highest<<".";

	cout << endl;
	system("pause");
	return 0;
}

void findHighest(double sales, string div, double& highest, string& highdiv) {
	if (highest == sales) {
		highdiv = highdiv + " and " + div; 
	}

	else {
		if (sales > highest) {
			highest = sales;
			highdiv = div; 
		}
	}
}


void getSales(double& sales ,string div) {
	cout << endl << "What is the " << div << "'s quarterly sales? ";
	cin >> sales;

	while (sales < 0) {
		cout << "Try again. Please enter a non-negative number with a decimal in the hundredths.\n"
			<< "Quarterly sales: ";
		cin >> sales;
	}

}


