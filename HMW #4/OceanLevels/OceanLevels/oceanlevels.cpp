/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: oceanlevels
* Purpose: Prints table that shows the change in ocean level over the next 25 years. 
*/

#include <iomanip>
#include <iostream>

using namespace std;

/*
* Function name: line()
* purpose: Prints dotted line
*/
void line();

int main() {
	cout << "The below table shows the ocean level over the next 25 years from now.\n"
		<<"The current ocean level is represented on year 0 at 0mm.\n\n";
	const float DELTA_OCEAN = 1.5; //1.5 mm per year
	cout <<setw(5)<<"Years"<<"| Ocean Rise (mm)\n";
	line();
	for (int i = 0; i <= 25; i++) {
		cout << endl << setw(5) << i << "| " << i * DELTA_OCEAN;
	}
	cout << endl;
	line();
	cout << endl;
	system("pause");
}

void line() {
	cout << "---------------------------";
}