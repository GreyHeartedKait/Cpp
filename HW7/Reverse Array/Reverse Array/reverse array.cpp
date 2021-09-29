//Uses program Quiz 25_Pointer_Array.cpp from Dr. Ma with modification 
//uses program Quiz_30_ArrayDuplication.cpp from Dr. Ma with modification

/*
* Author: Kaitlyn Bui
* Date: 06.14.2021
* Program: reverse array
* Purpose: Outputs reverse array 
*/
#include <iostream>
using namespace std;

int* reverseArray(const int [], int);
void displayArray(int [], int size); 

int main()
{
    int set[8] = { 5, 10, 15, 20, 25, 30, 35, 40 };
    int* reverse_set = nullptr; 

    // Display the numbers in the array.
    cout << "The numbers in set are:\n";
    displayArray(set, 8);
    cout << endl;

    // Display the numbers in reverse order.
    cout << "\nThe numbers in set backward are:\n";
    reverse_set = reverseArray(set, 8);
    displayArray(reverse_set, 8);

    delete[] reverse_set; 
    reverse_set = nullptr; 
    cout << endl << endl;
    system("pause");
    return 0;
}
//*********************************************
// reverseArray function
// input: array and size integer
// outputs: reversed array
//*********************************************
int* reverseArray(const int arr[], int size)
{
    if (size < 1)
        return nullptr;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = arr[size-1-i];
    }
    return array;
}

//**************************************************
// The displayArray function accepts an int array  *
// and its size as arguments and displays the      *
// contents of the array.                          *
// By Dr. Ma                                       *
//**************************************************

void displayArray(int ar[], int size) {				//displays array
    for (int i = 0; i < size - 1; i++) {
        cout << ar[i] << ", ";
    }
    cout << ar[size - 1];
}
