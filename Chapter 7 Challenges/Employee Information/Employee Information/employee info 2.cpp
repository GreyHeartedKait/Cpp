/*
* Author: Kaitlyn Bui
* Date: 05.31.2021
* Program: employee info
* Purpose: Collect, store, and display employee information
*/
#include <iostream>
#include <iomanip>
using namespace std;


long inputID();
int inputHours();
double inputPayRate();


int main() {
	//below constants are used to improve readability 
	const int EMP_NUM = 7;

	long empID[EMP_NUM] = { 5658845, 4520125, 7895122, 8777541, 8451277,1302850,7580489 };
	int empHours[EMP_NUM];
	double empRate[EMP_NUM];
	double empWages[EMP_NUM];

	for (int emp = 0; emp < EMP_NUM; emp++) {	//inputting values into array
		cout << "Please input information for employee " << empID [emp] << ".\n";
		//empID[emp] = inputID();
		empHours[emp] = inputHours();
		empRate[emp] = inputPayRate();
		empWages[emp] = empHours[emp]* empRate[emp];
		cout << endl;
	}

	//display vital employee information
	cout << "Employee Information Summary\n"
		<< "------------------------------------\n";
	for (int emp = 0; emp < EMP_NUM; emp++) {
		cout << "Employee #" << emp + 1
			<< "\nID: " << empID[emp]
			<< "\nGross wage: $" << fixed << setprecision(2) << showpoint << empWages[emp]
			<< endl << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}

long inputID() {	//receives and returns ID info
	long id;
	cout << "ID: ";
	cin >> id;
	return id;
}

int inputHours() {	//receives, validates, and returns hour info
	int hours;
	cout << "Hours: ";
	cin >> hours;
	while (hours < 0) {
		cout << "\nOne cannot work negative hours. Please input a new value.\n";
		cin >> hours;
	}

	return hours;
}

double inputPayRate() {	//receives, validates, and returns pay rate info
	double pay_rate;
	cout << "Pay/hour: $";
	cin >> pay_rate;
	while (pay_rate < 15) {
		cout << "\nThe pay per hour must be greater than $15. Please enter again.\n";
		cin >> pay_rate;
	}
	return pay_rate;
}