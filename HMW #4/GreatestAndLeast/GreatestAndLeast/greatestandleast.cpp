/*
* Author: Kaitlyn Bui
* Date: 05.11.2021
* Program: greatestandleast
* Purpose: Finds the greatest and least of a given list
*/
#include <iostream>

using namespace std;

int main() {
	int input, least, greatest; 
	cout << "Hello User!\n"
		<<"Please input numbers to receive the least and greatest of the group.\n"
		<<"type -99 to signify the end of the list.\n"
		<<"Example: 23 23 56 24 64 -99\n"
		<<"Numbers: ";
	
	cin >> input;
	least = greatest = input; 

	while (input != -99) {
		if (input > greatest) 
			greatest=input;
		
		else if (input < least) 
			least=input;
		
		cin >> input;
	}
	
	if (greatest == -99 && least == -99)
		cout << "\nNo number was given.\n\n";
	else
		cout << endl << "Least: " << least << " Greatest: " << greatest<<endl<<endl; 

	system("pause");
}