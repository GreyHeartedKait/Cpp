#include "Student.h"
#include <iostream>

void Student::setName(std::string n) {
	name = n;
}

void Student::setID(int num) {
	id = num;
}

void Student::setAddress(address stuAddress) {
	home_address = stuAddress;
}

void Student::addQuiz(int quiz) {
	if (quizCount == 0) {
		listQuizzes = new int[1];
		listQuizzes[0] = quiz;
		quizCount = 1;
	}

	else{
		int* hold = listQuizzes;
		listQuizzes = new int[quizCount + 1];

		for (int i = 0; i < quizCount; i++) {
			listQuizzes[i] = hold[i];
		}

		listQuizzes[quizCount] = quiz;

		quizCount++; 

		delete[] hold;
	}
}

double Student::getAverage(){
	if (quizCount <= 0) return -1;

	double total = 0;

	for (int i = 0; i < quizCount; i++) {
		total += listQuizzes[i];
	}

	return total / quizCount;
}

void Student::printQuizList(){
	if (quizCount <= 0) std::cout << "[]";

	else {
		std::cout << "[";
		for (int i = 0; i < quizCount; i++) {
			std::cout << listQuizzes[i] << ", ";
		}
		std::cout << listQuizzes[quizCount - 1] << "]";
	}
}

void Student::printStudentData(){
	std::cout <<"Name: " << name << std::endl;
	std::cout <<"ID:   " << id << std::endl;
	std::cout <<"Ad1:  " << home_address.street << std::endl;
	std::cout <<"Ad2:  " << home_address.city << std::endl;
	std::cout << "Ad3:  " << home_address.street << std::endl;
	std::cout << "Ad4:  " << home_address.state << std::endl;
	std::cout << "Ad5:  " << home_address.zip_code << std::endl;
}
