/*
* Author: Kaitlyn Bui
* Date: 05.17.2021
* Program: sales
* Purpose: Reads a sales-file and returns a sales report stating the highest, lowest, and average sale. 
*/
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream sales_data("C:\\Users\\User\\source\\repos\\C-\\EXAM_2\\sales-1.txt");
	double temp, lowest, highest, total=0;
	int num_of_sales=0;

	if (sales_data.fail()) //file error 
		cout << "Error. Cannot find given file.\n\n";

	if (sales_data >> temp) {
		num_of_sales++;
		total += temp;
		highest = lowest = temp;

		while (sales_data >> temp) {
			num_of_sales++;
			total += temp;

			if (temp > highest)
				highest = temp;

			else if (temp < lowest)
				lowest = temp;
		}
		cout << "The highest value is $" << highest << " and the lowest is $" << lowest << ".\n"
			<< "There are "<<num_of_sales<<" sales with and average sale value of $" << total / num_of_sales << ".\n\n";
	}

	else {	//if there is not a single value in file
		cout << "There are no values in this file.\n\n";
	}

	

	sales_data.close();

	system("pause");
}