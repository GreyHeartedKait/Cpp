/*
* Author: Kaitlyn Bui
* Date: 05.04.2021
* Program: Quiz 16
* Purpose: Reads a list of numbers from a file and outputs the # of numbers & avg. of nums
*/
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream file("C:\\Users\\User\\source\\repos\\C-\\Quiz 16\\Quiz 16\\Random.txt");
	int sum = 0, nums = 0, n;	//sum is the sum of all numbers, 
								//nums is the # of numbers
								//n is a temporary number-holding variable
	
	if (file.fail())	//file-opening error
		cout << "Error...File does not exist at given directory.";
	
	else{
		while (file>>n) {	//reads file & counts nums and adds the num value to sum
			sum += n;
			nums++;
		}

		cout << "Total number of numbers: " << nums << endl;
		cout << "Sum of all numbers: "<<sum<<endl;
		cout << "Average of all numbers: " << (sum * 1.0) / nums; //using 1.0 to prevent int. division
	}

	file.close();
	cout << endl<<endl;
	system("pause");
}