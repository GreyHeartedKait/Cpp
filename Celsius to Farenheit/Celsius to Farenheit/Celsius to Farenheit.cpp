/*
* Author: Kaitlyn Bui
* Date: 04.15.2021
* Program: Celsius to Farenheit
* Purpose: Converts from farenheit to celsius and vice versa. 
*/
#include <iostream>
#include <iomanip>

using namespace std;

/*Purpose: Takes a farenheit input and converts it to celsius.
* var input: the farenheit value entered.
*/
double FtoC(double input) {
	return (5*(input - 32) / 9);
}
/*Purpose: Takes a celsius input and converts it to farenheit.
* var input: the celsius value entered.
*/
double CtoF(double input) {
	return (9 * input / 5) + 32;
}

int main() {
	/*
	* var inputMeasure: the input's unit
	* var outputMeasure: the output's unit.
	* var input: the inputted value
	* var output: the outputted value.
	*/
	string inputMeasure, outputMeasure;
	double input, output;

	cout << "Hello user. Welcome to the Celsius to farenheit converter(and vice versa).\n"
		<<"Represent Fareinheit and Celsius with F and C.\n"
		<< "\nPlease enter the value you wish to convert: ";
	cin >> input >> inputMeasure;
	//directs inputs to different functions depending on measure
	if (inputMeasure == "F" || inputMeasure == "f") {
		output = FtoC(input);
		outputMeasure = "Celsius";
	}

	else {
		output = CtoF(input);
		outputMeasure = "Farenheit";
	}

	cout <<fixed<<setprecision(1)
		<<"\nOutput: " << output << " " << outputMeasure<<endl<<endl;

	system("pause");
}