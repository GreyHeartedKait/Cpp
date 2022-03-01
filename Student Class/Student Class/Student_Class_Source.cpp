/*
* This is a student class with a name, address, and quiz list. 
* By Kaitlyn Bui
* 01.14.2021 
*/

#include <iostream>
#include "Student.h"

int main() {
	address x = { "1234 Holes st SE", "Colorado City", "Florida", 67963 };
	
	Student s1;
	s1.setName("Harly");
	s1.setID(12345);
	s1.setAddress(x);

	s1.printStudentData();

	s1.addQuiz(10);
	s1.addQuiz(12);
	s1.addQuiz(10);

	std::cout << "Current quizzes = ";
	s1.printQuizList();
	std::cout << std::endl;

	std::cout << "Current Averages = " << s1.getAverage() << std::endl;


}