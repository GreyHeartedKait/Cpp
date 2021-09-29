// uses program Quiz_30_ArrayDuplication.cpp by Dr. Ma
/*
* Author: Kaitlyn Bui
* Date: 06.14.2021
* Program: double array size
* Purpose: returns an array that is double the size of the given array
*/
#include <iostream>
using namespace std;
void displayArray(const int[], int);
int* doubleSize(const int[], int);

int main() {
	// Define constants for the array sizes.
	const int SIZE1 = 5;

	// Define three arrays of different sizes.
	int array1[SIZE1] = { 100, 200, 300, 400, 500 };
	
	cout << "Here is the original array: ";
	displayArray(array1, SIZE1);
	cout << endl;

	cout << "Here is the array with a double size: ";
	int * doubled_array1 = doubleSize(array1, SIZE1);
	displayArray(doubled_array1, SIZE1);

	cout << endl;


	cout << endl << endl;
	system("pause");
	return 0;
}

int* doubleSize(const int array[], int size) {
	int* ar = new int[size * 2];

	return ar;
}


//**************************************************
// The displayArray function accepts an int array  *
// and its size as arguments and displays the      *
// contents of the array.                          *
//**************************************************

void displayArray(const int ar[], int size) {				//displays array
	for (int i = 0; i < size - 1; i++) {
		cout << ar[i] << ", ";
	}
	cout << ar[size - 1];
}