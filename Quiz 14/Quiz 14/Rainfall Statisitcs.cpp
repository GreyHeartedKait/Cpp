#include <iostream>
using namespace std;

double rfPerMonth(int month) {
	
	if (month > 0) {
		double rainfall;
		cout << "\nRainfall this month: ";
		cin >> rainfall;

		while (rainfall < 0) {
			cout << "\nPlease input a non-negative number."
				<< "\nRainfall this month: ";
			cin >> rainfall;
		}

		return rfPerMonth(month - 1) + rainfall;
	}
	else
		return 0;

}

double rfPerYear(int numOfYears) {
	if (numOfYears > 0) {
		return rfPerMonth(12)+rfPerYear(numOfYears-1);
	}

	else
		return 0;
}

int main() {
	int numOfYears;

	cout << "Number of Years: ";
	cin >> numOfYears;

	while (numOfYears < 0) {
		cout << "\nPlease enter a valid number of Years: ";
		cin >> numOfYears;
	}

	cout << "\nTotal Rainfall: " << rfPerYear(numOfYears);
}
