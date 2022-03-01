/*
* Programming Assignment #3 - Fractional Complex
* 
* The Fractional Complex Class allows one to implement the fractional complex,
* a fraction + fraction * complex Number,
* with appropriate arithmetic operations and boolean operators. 
* 
* Version #2 Edits
*	printme function removed
*	more operators added
*	Constructor w/ 2 parameters edited to accept x and y as a and b.
* 
* By Kaitlyn Bui
* 01.26.2021, Version #2 
* CS 132, Sec 12402, Prof. Wood
*/

#pragma once
#include <fstream>

class FractionalComplex
{
	private:
		int a;
		int b;
		int c;
		int d;

		//Helper Functions 
		void reduce();
		double length() const;

	public:
		//Constructors
		FractionalComplex(int, int, int, int); //mixed fraction and complex
		FractionalComplex(int, int); //fraction
		FractionalComplex(); // default

		//Functions
		bool isFrac() const;

		//Operators
		friend std::ostream& operator<< (std::ostream&, const FractionalComplex&);
		

		//Addition Operators
		FractionalComplex operator+(const FractionalComplex&) const;
		void operator+=(const FractionalComplex&);
		FractionalComplex operator+(int) const;
		friend FractionalComplex operator+(int, const FractionalComplex&);
		void operator+=(int);

		//Subtraction Operators
		FractionalComplex operator-(const FractionalComplex&) const;
		void operator-=(const FractionalComplex&);
		FractionalComplex operator-(int) const;
		void operator-=(const int);

		//Multiplication Operators
		FractionalComplex operator*(const FractionalComplex&) const;
		friend FractionalComplex operator*(int, const FractionalComplex&);
		void operator*=(const FractionalComplex&);
		FractionalComplex operator*(int) const;
		void operator*=(int);
		
		//Division Operators
		FractionalComplex operator/ (int) const;
		void operator/=(int);


		//Increment-Decrement Operators
		FractionalComplex operator++(); //pre-increment 
		FractionalComplex operator++(int); //post-increment
		FractionalComplex operator--(); //pre-decrement 
		FractionalComplex operator--(int); //post-decrement


		//Boolean Operators 
		bool operator==(const FractionalComplex&) const;
		bool operator<(const FractionalComplex&) const;
		bool operator>(const FractionalComplex&) const;	
		bool operator!=(const FractionalComplex&) const;
		bool operator<=(const FractionalComplex&) const;
		bool operator>=(const FractionalComplex&) const;
};

