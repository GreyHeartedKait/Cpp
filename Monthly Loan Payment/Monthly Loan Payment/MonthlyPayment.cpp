#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double payment(int n, double rate, double l) {
	return l * (rate * pow((1 + rate), n)) / (pow((1 + rate), n) - 1);
}

int main() {
	double monthlyInterest, loan, monthlyPayment;
	int numPay;
	
	cout << fixed <<setprecision(2)<<showpoint;

	cout << "Hello user! Welcome to the loan calculator. This program will calculate and display details for a loan.\n"
		<< "Please enter the following values: \n\n"
		<< "Loan Amount: ";
	cin >> loan;
	cout << "Monthly Interest (%): ";
	cin >> monthlyInterest;
	monthlyInterest /= 100;
	cout << "# of payments: ";
	cin >> numPay;
	monthlyPayment = payment(numPay, monthlyInterest, loan);

	cout << endl << left << setw(25) << "Loan amount:" << "$" << right << setw(10) << loan
		<< endl <<left << setw(25) << "Monthly Interest Rate:" << right << setw(10) << monthlyInterest * 100 << "%"
		<< endl << left << setw(25) << "Number of Payments:" << right << setw(11) << numPay
		<< endl << left << setw(25) << "Monthly Payment:" << "$" << right << setw(10) << monthlyPayment
		<< endl << left << setw(25) << "Amount paid back:" << "$" << right << setw(10) << monthlyPayment * numPay
		<< endl << left << setw(25) << "Interest Paid:" << "$" << right << setw(10) << monthlyPayment * numPay - loan<<endl<<endl;

	system("pause");
	

}