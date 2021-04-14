#include <iomanip>
#include <iostream>
using namespace std;

/*
* Purpose: Draws line.
*/
void line() {
	cout << "--------------------------------";
}

int main() {
	int soldA, soldB, soldC;
	double priceA = 15.3, priceB = 12.25, priceC = 9.9, sum;

	cout << "Hello user. Welcome to the ticket price table.\n"
		<< "Please input the following values:\n\n"
		<< setw(20) << "# of A tickets sold: ";
	cin >> soldA;

	cout << setw(20) << "# of B tickets sold: ";
	cin >> soldB; 

	cout << setw(20) << "# of C tickets sold: ";
	cin >> soldC;

	sum = (soldA * priceA) + (soldB * priceB) + (soldC * priceC);
	cout << setprecision(2) << fixed << showpoint<<endl;
	line();
	cout <<endl<< setw(16) << "$/unit"
		<< setw(8) << "# sold"
		<< setw(8) << "total"
		<< endl;
				
	line();
	
	cout << endl << setw(8) << "class A" << setw(8) << priceA << setw(8)
		<< soldA << setw(8) << soldA * priceA
		<< endl << setw(8) << "class B" << setw(8) << priceB << setw(8)
		<< soldB << setw(8) << soldB * priceB
		<< endl << setw(8) << "class C" << setw(8) << priceC << setw(8)
		<< soldC << setw(8) << soldC * priceC << endl;
	line();
		cout <<endl <<setw(24) << "sum" << setw(8) << sum<<endl;
	cout << endl;
	system("pause");
	
}