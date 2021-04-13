/*
* Author: Kaitlyn Bui
* Date: 04.13.2021
* Program: Quiz 5
* Purpose: Calculate the balance of a bank account.
*/

#include <iostream>
#include <cmath>

using namespace std; 
/*
* Purpose: Draws line.
*/
void line() {
	cout << "-----------------------------------------------------------------------------------\n";
}
/*
* Purpose: Calculates the end savings from compund interest after 1 year.
*/
double savings(float principal, float rate, int t) {
	return principal * pow((1 + (rate/100) / t), t);
}

int main() {
	/*Variable initialization.
	* var principal: The intial amount.
	* var rate: The rate of interest as a percentage.
	* var t: the number of times interest in compounded in 1 year.
	* var foo: used in while loop to continue or discontinue calculating. Set to 1 to start the first round of the while loop.
	*/
	float principal, rate;
	int t, foo;
	foo = 1;

	cout << "Hello user. Welcome to the investment calculator.\n\n";

	while(foo==1){													//Asking for inputs.
		cout << "Please enter the following information:\n"		
		<< "Principal amount ($): ";
		cin >> principal;
		cout << "\nRate (%): ";
		cin >> rate;
		cout << "\n# of times interest is compounded per year: ";
		cin >> t;
		cout << endl;
		line();
		cout << "Report\n\n"										//Giving report with calculated values
			<< "Interest Rate: " << rate << "%\n"
			<< "Times compounded: " << t
			<< "\nPrincipal: $" << principal
			<< "\nInterest: $" << savings(principal, rate, t)-principal
			<< "\nAmount in savings: $" << savings(principal, rate, t)	
			<< endl;
		line();
		cout << endl
			<< "Would you like to calculate again?(1 for yes, 0 for no): "; //asks for foo value
		cin >> foo;
		cout << endl;
	}
	system("pause");
}