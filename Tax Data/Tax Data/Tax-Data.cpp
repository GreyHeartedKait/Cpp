/*	This program will receive a file of names and incomes as input and ouput each entity's owed taxes.
	By: Kaitlyn Bui
	CS 132 - Assignment #1 Wood
	01.07.2021
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int calculateTaxes(double income);

int main() {
	//read file, create output file
	ifstream file("C:\\Users\\User\\Documents\\C++ Data Structures\\Assignment 1\\Families.txt");
	ofstream tax_report;
	tax_report.open("Data.txt");

	//file does not exist or fails to open.
	if (file.fail()) cout << "Error...File does not exist at given directory.";

	string name;
	double income; 

	//print out headers
	tax_report << fixed << setprecision(0)<<left;
	tax_report << setw(10)<< "Name" << setw(15)<< "Income" <<setw(10)<< " Taxes Owned"<<endl;
	tax_report << "---------------------------------------"<<endl;
	

	//while a name exists
	while (file >> name) {
		file >> income;
		//print name, income, and taxes owed
		tax_report << setw(10) << name <<"$" << setw(15) << income << "$" << setw(10) << calculateTaxes(income) << "\n"; //<< endl;

	}

	tax_report.close();
	file.close();

	return 0;
}
/*
* This function calculates the base tax owed based on someones income.
*/
int calculateTaxes(double income) {
	double taxesOwed = 0;

	//If income is over 100k, add appropriate amount of taxes
	if (income > 100000) {
		taxesOwed += (income - 100000) * .4;
		income = 100000;
	}

	//if income is over 100k or over 30k, add taxes
	if (income > 30000) {
		taxesOwed += (income - 30000) * .25;
		income = 30000;
	}

	//if income is over 100k, 30k, or 10k, add appropriate taxes
	if (income > 10000) {
		taxesOwed += (income - 10000) * .1;
	}

	//round to the nearest whole number
	return round(taxesOwed);
}