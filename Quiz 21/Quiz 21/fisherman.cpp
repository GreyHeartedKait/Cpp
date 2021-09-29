/*
* Author: Kaitlyn Bui
* Date: 05.18.2021
* Program: Fishermen
* Purpose: Use an array to store how many fish each of 20 fishermen caught 
*/
#include <iostream>
using namespace std;

int main() {
	const int fishermen = 20;
	int fish[fishermen];
	for (int i = 0; i < fishermen; i++) {
		cout << "How many fish were caught by fisherman " << i+1 << "? ";
		cin >> fish[i];
	}

	cout << endl;

	for (int i = 0; i < fishermen; i++) {
		cout << "Fishermen #"<<i+1<<" caught "<<fish[i]<<" fish.\n";
	}

	cout << endl<<endl;

	system("pause");
}