/*
* Author: Kaitlyn Bui
* Date: 05.24.2021
* Program: function_processing_array
* Purpose: Input values into an array and process using functions
*/
#include <iostream>
using namespace std;

void getTestScores(double[], const int);

double getTotal(const double[],const int);

int main(){
	int const SIZE = 5; 
	double testScores[SIZE];
	
	getTestScores(testScores, SIZE);
	cout<<endl<<"The total score is "<<getTotal(testScores, SIZE)<<". \n\n";

	system("pause");
}

void getTestScores(double tests[], const int SIZE) {	//inputs values into function
	cout << "Please enter " << SIZE << " test scores:\n";

	for (int i = 0; i < SIZE; i++) {
		cout << "Test score #" << i + 1 << ": ";
		cin >> tests[i];
	}
}

double getTotal(const double nums[], const int SIZE) {	//returns sum of all values in an array
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += nums[i];
	}
	
	return sum; 
}