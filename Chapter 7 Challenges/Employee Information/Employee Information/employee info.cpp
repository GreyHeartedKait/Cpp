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


/*int main() {
	//below constants are used to improve readability 
	const int ID = 0,	//column ID info is in
		HOURS = 1,		//column hours info is in
		PAY_RATE = 2,	//column pay rate info is in
		WAGES = 3,		//column wage info is in
		EMP_NUM = 7,	//array row size, the number of employees
		EMP_INFO = 4;	//array column size, the number of employee-stats

	double emps[EMP_NUM][EMP_INFO];	//rows are designate which employee, columns, which employee-stat

	for (int i = 0; i < EMP_NUM; i++) {	//inputting values into array
		cout << "Please input information for employee #" << i+1 << ".\n";
		emps[i][ID] = inputID();
		emps[i][HOURS] = inputHours();
		emps[i][PAY_RATE] = inputPayRate();
		emps[i][WAGES]= emps[i][HOURS]*emps[i][PAY_RATE];
		cout << endl;
	}

	//display vital employee information
	cout << "Employee Information Summary\n"
		<<"------------------------------------\n";
	for (int i = 0; i < EMP_NUM; i++) {
		cout << "Employee #" << i + 1
			<< "\nID: " << fixed << setprecision(0)<<noshowpoint << emps[i][ID]
			<< "\nGross wage: $" << fixed << setprecision(2) << showpoint << emps[i][WAGES]
			<< endl<<endl;
	}

	cout <<endl;
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
}*/
