/*
* Author: Kaitlyn Bui
* Date: 06.02.2021
* Program: largest_value
* Purpose: prints out array and the largest value and its subscript. 
*/
#include <iostream>
using namespace std;

int largestValue(int[], int);
void displayArray(const int ar[], int size);

int main() {
	int array[] = { 4, 3, 2, 1, 3 };
	int foo = largestValue(array, 5);
	cout << "For array ["; 
	displayArray(array, 5);
	cout<< "], the largest value is " << array[foo] << " at subscript " << foo << "."
		<< endl << endl;
	system("pause");
	return 0;
}

int largestValue(int array[], int size) {
	int temp=0;
	for (int i = 1; i < size; i++) {
		if (array[i] > array[temp])
			temp = i;
	}
	return temp; 
}

void displayArray(const int ar[], int size) {				//displays array
	for (int i = 0; i < size - 1; i++) {
		cout << ar[i] << ", ";
	}
	cout << ar[size - 1];
}