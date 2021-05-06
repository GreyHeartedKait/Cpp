/*
* Author: Kaitlyn Bui
* Date: 05.06.2021
* Program: Quiz 17 - Practicing Functions
* Purpose: To practice and utilize functions
*/
#include <iostream>
using namespace std;

void print_star();
void print_message();


int main() {
	print_star();
	cout << endl;
	print_message();
	cout << endl;
	print_star();
	cout << endl;

	system("pause");
}

void print_star() {
	cout << "* * * * * * * * * *";
}

void print_message() {
	cout << "How do you do?";
}