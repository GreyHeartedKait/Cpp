/*
* Author: Kaitlyn Bui
* Date: 05.31.2021
* Program: test correcter
* Purpose: Grades a multiple-choice test
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool CIV(char, char[], int);
void displayArray(const char[], int, string);	
void displayArray(const char[], int);

int main() {
	const int NUM_QUESTIONS = 20;		//number of questions on test
	const double PASSING_SCORE = .75;	//Score percentaged needed to pass
	const int NUM_ANSWERS = 4;			//The number of possible answers, size of allowed answers array
	int num_wrong = 0,					//number of questions answered incorrectly
		num_right;						//number of questions answered correctly 
	double score;						//Student's test score

	char answer_key[NUM_QUESTIONS] =   {'a', 'b','a',	//array of correct answers
										'c','d','a',
										'c', 'c', 'b',
										'b', 'd', 'a',
										'b', 'c', 'b',
										'd','c','d',
										'd','b'};
	char student_answers[NUM_QUESTIONS];				//student's answers
	int student_wrong[NUM_QUESTIONS];					//questions student got wrong
	char allowed[NUM_ANSWERS] = { 'a','b','c','d' };	//valid answers to question
	
		//-----------------------------------------
		//			 ANSWER COLLECTION		    
		//-----------------------------------------

	cout << "Please enter your answers below.\n";
	for (int i = 0; i < NUM_QUESTIONS; i++) {			//iterates over every question
		char answer;
		cout << "Question #"<<i+1<<" ---> ";
		cin >> answer;
		answer = tolower(answer);
		while (!CIV(answer, allowed, NUM_ANSWERS)) {	//CIV == Character Input Validation, validation loop
														//ensures answer is in allowed answers array
			cout << "\nPlease enter ";				
			displayArray(allowed, NUM_ANSWERS, "or");	//displays allowed values: a, b, c, or d
			cout<<".\n"
				<< "Question #" << i + 1 << " ---> ";
			cin >> answer;
		}
		student_answers[i] = answer;					
		if (answer != answer_key[i]) {					//if answer is wrong, store the question number in student_wrong
			student_wrong[num_wrong] = i;				//add 1 to the num_wrong counter
			num_wrong++; 
		}

	}
	num_right = NUM_QUESTIONS - num_wrong;
	
	//-----------------------------------------
	//			 DISPLAY SCORE		    
	//-----------------------------------------

	cout << endl << endl
		<< "Passing score: " << ceil(PASSING_SCORE * NUM_QUESTIONS) << "/" << NUM_QUESTIONS
		<< " or " << ceil(PASSING_SCORE * 100) << "%.\n"	//rounds up percentage & required # of correct answers
		<<"-----------------------------------\n";

	score = num_right * 1.0 / NUM_QUESTIONS;

	if (score>= PASSING_SCORE) {	//If student passed, print pass
		cout << "PASSED";
	}
	else {							//If student failed, print failed
		cout << "FAILED";
	}
	cout << "\n\nScore: " << num_right << "/" << NUM_QUESTIONS;	//print score

	if (num_wrong > 0) {			//if student got problems wrong,
		cout << "\n\nIncorrect Answers:\n"
			<< "-----------------------------------\n";
		for (int i = 0; i < num_wrong; i++) {
			cout << "Question #" << student_wrong[i]
				<< "\n\nYour answer: " << student_answers[student_wrong[i]]
				<< "\n\nCorrect answer:" << answer_key[student_wrong[i]]
				<< endl;
		}
	}
	else                           //If student got a perfect score,
		cout << "\n\nPerfect score!";

	cout << endl << endl;
	system("pause");
	return 0;
}
/*
* Function: CIV or Character Input Validation
* Purpose: Ensures given input is valid.
*/
bool CIV(char input, char allowed[], int size) {
	sort(allowed, allowed+size);
	return binary_search(allowed, allowed+size, input);
}


void displayArray(const char ar[], int size, string c) {	//displays array with a conjunction phrase before the last value
	displayArray(ar, size - 1);
	cout<<", "<< c << " " << ar[size - 1];
}

void displayArray(const char ar[], int size) {				//displays array
	for (int i = 0; i < size - 1; i++) {
		cout << ar[i] << ", ";
	}
	cout << ar[size - 1];
}

