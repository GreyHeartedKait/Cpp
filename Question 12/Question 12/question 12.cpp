#include <iostream>

using namespace std;

void getScore(int&);

void calcAvg(int, int, int, int, int);

int findLowest(int, int);

int findLowest(int, int, int, int, int);

int main() {
	int s1, s2, s3, s4, s5; 
	
	getScore(s1);
	getScore(s2);
	getScore(s3);
	getScore(s4);
	getScore(s5);

	calcAvg(s1, s2, s3, s4, s5); 

	cout << endl;

	system("pause");
}

void getScore(int& score) {
	cout << "Please enter a test score: ";
	cin >> score;
}

void calcAvg(int s1, int s2, int s3, int s4, int s5) {
	int lowest = findLowest(s1, s2, s3, s4, s5);

}

int findLowest(int s1, int s2, int s3,int  s4,int s5) {
	int lowest = findLowest(s1, s2);
	lowest = findLowest(lowest, s3);
	lowest = findLowest(lowest, s4);
	return findLowest(lowest, s5);
}

int findLowest(int s1, int s2) {
	return (s1 < s2) ? s2 : s1; 
}