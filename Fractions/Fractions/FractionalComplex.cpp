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

#include "FractionalComplex.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

//Constructors------------------------------------


//Default Constructor 
FractionalComplex::FractionalComplex() { 
	a = 0;
	b = 1;
	c = 0;
	d = 1;
}

//Fraction-Only Constructor
FractionalComplex::FractionalComplex(int x, int y) { 
	if (y == 0) {
		x = 0;
		y = 1;
	}

	a = x;
	b = y;
	c = 0;
	d = 1; 

	reduce();
}

//Fractional Complex constructor
FractionalComplex::FractionalComplex(int _a, int _b, int _c, int _d) { 
	if (_d == 0) { //if c/0, then replace with 0/1.
		_c = 0;
		_d = 1;
	}

	if (_b == 0) { //if a/0, replace with 0/1. 
		_a = 0;
		_b = 1;
	}
	
	a = _a;
	b = _b;
	c = _c;
	d = _d;

	reduce();
}


//Functions-----------------------------------------------------


/* is a fraction
* 
* This function determines if the fractional complex is only a fraction
*/
bool FractionalComplex::isFrac() const {
	return ((c == 0) && (d == 1));
}


//Operators------------------------------------------------------


/* << Operator */
std::ostream& operator<< (std::ostream& stream, const FractionalComplex& fraction) {
	if (fraction.isFrac()) {
		stream << "[" << fraction.a << "/" << fraction.b << "]";
	}

	else {
		stream << "[(" << fraction.a << "/" << fraction.b << ") + "
			<< "(" << fraction.c << "/" << fraction.d << ")i]";
	}
	return stream;
}


//Addition Operators-----------------------------------------


/* Fractional Complex + Fractional Complex */
FractionalComplex FractionalComplex::operator+(const FractionalComplex& rhs) const {
	//Fraction addition
	// x    a*_b + _a *b     a    _a
	//--- = ------------- = --- + ---
	// y       _b * b        b    _b

	int _a = rhs.a*this->b + this->a * rhs.b; 
	int _b = rhs.b*this->b;
	int _c = rhs.c * this->d + this->c * rhs.d;
	int _d = rhs.d * this->d;

	return FractionalComplex(_a, _b, _c, _d);
}

/* Fractional Complex += Fractional Complex */
void FractionalComplex::operator+=(const FractionalComplex& rhs) {
	int _a = rhs.a * this->b + this->a * rhs.b;
	int _b = rhs.b * this->b;
	int _c = rhs.c * this->d + this->c * rhs.d;
	int _d = rhs.d * this->d;

	a = _a;
	b = _b;
	c = _c;
	d = _d;

	reduce();
}

/* Fractional Complex + integer */
FractionalComplex FractionalComplex::operator+(int x) const{
	return FractionalComplex(a + x * b, b, c, d);
}

/* int + Fractional Complex */
FractionalComplex operator+(int x, const FractionalComplex& fraction){
	return (fraction + x);
}

/* FractionalComplex += int */
void FractionalComplex::operator+=(int x){
	a += x * b;

	reduce();
}


//Subtraction Operators--------------------------------------


/* Fractional Complex - Fractional Complex */
FractionalComplex FractionalComplex::operator-(const FractionalComplex& rhs) const {
	//Fraction subtraction
	// x    a*_b - _a *b     a       _a
	//--- = ------------- = ---  --  ---
	// y       _b * b        b       _b

	int _a = this->a * rhs.b - rhs.a * this->b ;
	int _b = rhs.b * this->b;
	int _c = this->c * rhs.d - rhs.c * this->d;
	int _d = rhs.d * this->d;

	return FractionalComplex(_a, _b, _c, _d);
}

/* Fraction complex -= Fractional Complex */
void FractionalComplex::operator-=(const FractionalComplex& rhs){
	int _a = this->a * rhs.b - rhs.a * this->b;
	int _b = rhs.b * this->b;
	int _c = this->c * rhs.d - rhs.c * this->d;
	int _d = rhs.d * this->d;

	a = _a;
	b = _b;
	c = _c;
	d = _d;
	reduce();
}

/* Fractional Complex - Integer */
FractionalComplex FractionalComplex::operator-(int x) const{
	return FractionalComplex(a - x * b, b, c, d);
}

/* Fractional Complex -= Integer */
void FractionalComplex::operator-=(int x) {
	a -= x * b;
	
	reduce();
}


//Multiplication Operators-----------------------------------


/* Fractional Complex * Fractional Complex
* 
* [a\b + c\d i] * [w/x + y/z i] = [aw/bx + ay/bz i] + [-cy/dz + cw/dx i]
*/
FractionalComplex FractionalComplex::operator*(const FractionalComplex& rhs) const {
	FractionalComplex x (a * rhs.a, b * rhs.b, a * rhs.c, b * rhs.d);
	FractionalComplex y(-1 * c * rhs.c, d * rhs.d, c * rhs.a, d * rhs.b);

	return x + y;
}

/* Fractional Complex *= Fractional Complex */
void FractionalComplex::operator*=(const FractionalComplex& rhs){
	*this = (*this) * rhs;
}

/* Fraction Complex * Integer
* 
* This is the multiplication operator. It allows you to multiple the fractional complex by an integer. 
* [a/b + c/d i] * x = [ax/b + cx/d i]
*/
FractionalComplex FractionalComplex::operator*(int x) const {
	return FractionalComplex(a * x, b, c * x, d);
}

/* Integer * Fractional Complex */
FractionalComplex operator*(int x, const FractionalComplex& fraction) {
	return (fraction * x);
}

/* Fractional Complex *= Integer */
void FractionalComplex::operator*=(int x){
	a *= x;
	c *= x;

	reduce();
}


//Division Operators--------------------------------------


/* Fractional Complex / Integer */
FractionalComplex FractionalComplex::operator/ (int x) const {
	if (x == 0) {
		std::cout << "\nInvalid Argument. Cannot divide by 0.\n";
		exit(EXIT_FAILURE);
	}

	int _a = a, _b = b, _c = c, _d = d;

	if (_a % x == 0) _a /= x;
	else _b = _b * x;

	if (_c % x == 0) _c /= x;
	else _d = _d * x;

	return FractionalComplex(_a, _b, _c, _d);
}

/* Fractional Complex /= Integer */
void FractionalComplex::operator/=(int x){
	*this = *this / x;
}


//Increment/Decrement Operators----------------------------


/* ++Fractional Complex - Pre-Increment */
FractionalComplex FractionalComplex::operator++() {
	//increment
	a += b;
	c += d;

	reduce(); 

	return *this; //return incremented value in original address
}

/* Fractional Complex++ - Post-Increment */
FractionalComplex FractionalComplex::operator++(int x) {
	FractionalComplex temp = *this; 
	++(*this); //increment value in original address

	return temp; //return temp value before incremented
}

/* --Fractional Complex - Pre-Decrement */
FractionalComplex FractionalComplex::operator--(){
	*this -= 1;
	return *this;
}

/* Fractional Complex-- - Post-Decrement */
FractionalComplex FractionalComplex::operator--(int x){
	FractionalComplex temp = *this;
	*this -= 1;
	
	return temp;
}



//Boolean Operators--------------------------------------------


/* Fractional Complex == Fractional Complex */
bool FractionalComplex::operator==(const FractionalComplex& rhs) const {
	if (a != rhs.a) return false;
	if (b != rhs.b) return false;
	if (c != rhs.c) return false;
	if (d != rhs.d) return false;

	return true; 
}

/* Fractional Complex < Fractional Complex */
bool FractionalComplex::operator<(const FractionalComplex& rhs) const{
	return (length() < rhs.length());
}

/* Fractional Complex > Fractional Complex */
bool FractionalComplex::operator>(const FractionalComplex& rhs) const{
	return (length() > rhs.length());
}

/* Fractional Complex != Fractional Complex */
bool FractionalComplex::operator!=(const FractionalComplex& rhs) const {
	return !(*this == rhs);
}

/* Fractional Complex <= Fractional Complex */
bool FractionalComplex::operator<=(const FractionalComplex& rhs) const{
	return ((*this == rhs) || *this < rhs);
}

/* Fractional Complex >= Fractional Complex */
bool FractionalComplex::operator>=(const FractionalComplex& rhs) const{
	return ((*this == rhs) || *this > rhs);
}


//Helper Functions------------------------------------------


/* Reduce
* 
* This function helps ensure negatives fractions are in the correct format. 
*	- negatives in the numerator
*	- simplification
*	- 0/n --> 0/1
*/
void FractionalComplex::reduce() {
	//if a/-b or -a/-b --> -a/b a/b
	if (d < 0) {
		d *= -1;
		c *= -1;
	}

	if (b < 0) {
		b *= -1;
		a *= -1;
	}

	//simplify a/b
	for (int i = abs(a); i > 0; i--) {
		if ((b % i == 0) && (a % i == 0)) {
			b /= i;
			a /= i;

			//once a/b is simplified, exit the loop
			i = -1;
		}
	}

	//simplify c/d
	for (int i = abs(c); i > 0; i--) {
		if ((c % i == 0) && (d % i == 0)) {
			d /= i;
			c /= i;

			//once c/d is simplified, exit the loop
			i = -1; 
		}
	}

	// 0/x --> 0/1
	if (a == 0) b = 1;

	// 0/x --> 0/1
	if (c == 0) d = 1;
}

/* Length Function *
*
* This function Prints out the length of a fractional complex.
*/
double FractionalComplex::length() const{
	//sqrt [(a/b)^2 + (c/d)^2]
	return sqrt(pow((double)a / b, 2) + pow((double)c / d, 2));
}



