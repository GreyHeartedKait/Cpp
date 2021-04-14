/*
* Author: Kaitlyn Bui
* Date: 04.13.2021
* Program: Annual Pay
* Purpose: Calculates the annual pay of a certain employee.
*/
#include <iostream>
using namespace std;
/*
* var payAmount: Amount paid each period
* var payPeriods: number of times paid in a year
* var annualPay: total paid each year
*/
int main() {
	float payAmount = 2200, payPeriods = 26, annualPay=payAmount*payPeriods;
	cout << annualPay;
	system("pause");
}