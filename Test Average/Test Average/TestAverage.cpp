/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Test Average
* Prpose: Input 5 test scores, receive the average test score. 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	float score1, score2, score3, score4, score5; 
	cout << "Hello user! Welcome to the test average calculator."
		<< "\nPlease enter in 5 test scores."
		<< "\n\nScore 1: ";
	
	cin >> score1;
	cout << "Score 2: ";
	cin >> score2;
	cout << "Score 3: ";
	cin >> score3;
	cout << "Score 4: ";
	cin >> score4;
	cout << "Score 5: ";
	cin >> score5;

	cout << fixed << setprecision(1);
	cout<<"\n\nYour score average is "<<(score1+score2+score3+score4+score5)/5.0<<".\n";

	system("pause");
}