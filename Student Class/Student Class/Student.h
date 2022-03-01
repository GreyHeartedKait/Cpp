#pragma once
#include <string> //class inside a class needs to be included

struct address {
	std::string street;
	std::string city;
	std::string state;
	int zip_code;
};

class Student
{
	private:
		std::string name;
		int id;
		address home_address; 

		int* listQuizzes;
		int quizCount = 0;

	public:
		void setName(std::string);
		void setID(int);
		void setAddress(address);

		void addQuiz(int);

		double getAverage();

		void printQuizList();
		void printStudentData();
};


