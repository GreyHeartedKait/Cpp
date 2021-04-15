#include<cmath>
#include <iostream>

using namespace std;

int main() {
	const double PI = 3.1415926535897932384626433832795028841;
	const double SLICE_SIZE = 14.125;
	double diameter, area;

	cout << "Hello user. Welcome to the pizza slice calculator,"
		<< "guaranteed to tell the exact # of slices/pie.\n"
		<< "Please input the diameter of the pizza(inches): ";
	cin >> diameter;

	area = pow(diameter / 2, 2) * PI;

	cout << "This pizza has " << round(area / SLICE_SIZE)<<" slices.\n";

	system("pause");
}
