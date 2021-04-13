/*
* This is the introductory comment, it's purpose is to give the user
* important information about the program and author. 
* Author: Kaitlyn Bui
* Date: 04.12.2021
* Program: Quiz 2
* Purpose: The purpose of this program is to show comprehension of the parts of a program and recently learned functions in class
* (cout and cin).

*/

#include <iostream> //preprocessor directive, allows program to use the input output stream
#include <string>
using namespace std; //This line tells the program which namespace to use, 
//which allows one to use the named entites within the namespace "standard"

void printer(string name, string date){ //header of function named 'printer'
	/*Input: 
	* string name: the name to be printed in the statement
	* string date: today's date
	* Output/purpose: To print three chosen sentences. 
	*/
	cout << "My name is " + name + "." << endl << "Today is " + date + "." << endl << "I'm writing a program in C++ now!";
	
}

int main() /*beginning of function main*/{//the start of the function body
	/*Purpose:
	* Invokes function printer()
	*/
	string name, date; //declaration of variable type
	name = "Kaitlyn Bui"; //string variable
	date = "12th of April"; //string variable

	printer(name, date); //function call
}//end of function main()