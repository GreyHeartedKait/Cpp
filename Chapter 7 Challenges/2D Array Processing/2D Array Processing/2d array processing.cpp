/*
* Author: Kaitlyn Bui
* Date:
* Program:
* Purpose:
*/
#include <iostream>
using namespace std;

int const NUM_ROWS = 2;
int const NUM_COLUMNS=3;

void displayArray(double arr[][NUM_COLUMNS], int num_rows);
double getAverage(double arr[][NUM_COLUMNS], int num_rows);
double getTotal(double arr[][NUM_COLUMNS], int num_rows);
double getRowTotal(double arr[][NUM_COLUMNS], int row);
double getColumnTotal(double arr[][NUM_COLUMNS], int num_rows, int col);
double getLowestInRow(double arr[][NUM_COLUMNS], int row);
double getHighestInRow(double arr[][NUM_COLUMNS], int row);

int main() {
    double arr[NUM_ROWS][NUM_COLUMNS] = { {1, 2, 3},
                                          {4, 5, 6} };

    cout << "Operations will be made using the following array:\n\n";

    displayArray(arr, NUM_ROWS);

    cout << "\nAverage value in array: " << getAverage(arr, NUM_ROWS)
        << "\nTotal of array: " << getTotal(arr, NUM_ROWS)
        << "\nRow totals: \n"
        << "\tRow one: " << getRowTotal(arr, 0) << endl
        << "\tRow Two: " << getRowTotal(arr, 1) << endl
        << "Column totals: \n"
        << "\tRow column one : " << getColumnTotal(arr, NUM_ROWS, 0) << endl
        << "\tRow column two : " << getColumnTotal(arr, NUM_ROWS, 1) << endl
        << "\tRow column three : " << getColumnTotal(arr, NUM_ROWS, 2) << endl
        << "Row stats: \n"
        << "\tHighest in row one: " << getHighestInRow(arr, 0) << endl
        << "\tLowest in row one: " << getLowestInRow(arr, 0) << endl
        << "\tHighest in row two: " << getHighestInRow(arr, 1) << endl
        << "\tLowest in row two: " << getLowestInRow(arr, 1) << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}

double getAverage(double arr[][NUM_COLUMNS], int num_rows) {
    double total = getTotal(arr, num_rows);

    return (total / num_rows) / NUM_COLUMNS;
}

double getTotal(double arr[][NUM_COLUMNS], int num_rows) {
    double total = 0;
    for (int col = 0; col < NUM_COLUMNS; col++)
    {
        total += getColumnTotal(arr, num_rows, col);
    }
    return total;
}

double getRowTotal(double arr[][NUM_COLUMNS], int row) {
    double total=0;

    // Sum a row.
    for (int col = 0; col < NUM_COLUMNS; col++)
        total += arr[row][col];


    return total;
}

double getColumnTotal(double arr[][NUM_COLUMNS], int num_rows, int col) {
    double total=0;

    for (int row = 0; row < num_rows; row++)
        total += arr[row][col];

    return total;
}

double getHighestInRow(double arr[][NUM_COLUMNS], int row) {
    double highest = arr[row][0];
    for (double value : arr[row]) {
        if (value > highest)
            highest = value;
    }
    return highest;
}

double getLowestInRow(double arr[][NUM_COLUMNS], int row) {
    double lowest = arr[row][0];
    for (double value : arr[row]) {
        if (value < lowest)
            lowest = value;
    }
    return lowest;
}

void displayArray(double arr[][NUM_COLUMNS], int num_rows){
    for (int row = 0; row < num_rows;row++) {
        cout << "{"<<arr[row][0];
        for (int col = 1; col < NUM_COLUMNS; col++) {
            cout << ", " << arr[row][col];
        }
        cout << "}\n";
    }
}