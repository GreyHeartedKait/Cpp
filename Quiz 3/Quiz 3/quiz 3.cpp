#include <iostream>
using namespace std;

/*
* Author: Kaitlyn Bui
* Date: 04.12.2021
* Program: quiz 3
* purpose: Calculate the average test score of three students 
*/


int main() {//prefaces user to answer further promts
	cout << "Hello user. This program aims to find the average score of three students.\n";
	cout << endl;
	system("pause");
	cout << endl;
	float average;
	int student1, student2, student3, choice; //intializing vars

	cout << "Would you like to use default numbers or enter your own?\n"; 
	cout << "Enter 1 for default and 0 for custom: "; //default uses the prompts originals problems
	cin >> choice; 
	cout << endl;

	if (choice == 1) {
		
		student1 = 85;
		student2 = 86; //assigns varaibles 
		student3 = 92;
		cout << "Understood. There scores are 85, 86, and 92. Please wait, thank you!\n";
	}
	else {
		cout << "Understood. Please enter the three scores you would like to average: \n"<< endl;
		cout << "Score 1: ";
		cin >> student1; //This sections asks for user input to assign the variables. 
		cout << "Score 2: ";
		cin >> student2;
		cout << "Score 3: ";
		cin >> student3;
		cout << endl; 
	}

	// #ImplicitConversionThrowsErrors
	//average = (student1 + student2 + student3) / 3.0; 
	average = float(student1 + student2 + student3) / 3; //computes the average from given values 
	system("pause");
	cout << endl;
	cout << "Here is the average: " << average<< endl <<endl;

	system("pause");
	
}