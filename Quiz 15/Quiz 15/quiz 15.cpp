/*
* Author: Kaitlyn Bui
* Date: 05.03.2021
* Program: Quiz 15
* Purpose: Reads input files, processes, and outputs information
*/
#include <iostream>
#include <fstream>
	
using namespace std;

int main() {
	ifstream iFile("C:\\Users\\User\\source\\repos\\C++ Class Repos\\Tester\\Tester\\Friends.txt");
	string foo;

	for (int i =1; i <= 3; i++) {	//prints out three names of friends 
		iFile >> foo;
		cout << "Friend #" << i << ": " << foo << endl;
	}

	iFile.close(); 

	system("pause");
}