#include <iostream>
#include <cmath>

using namespace std;

double bmiCalc(double weight, double height){
	return weight * (703 / pow(height, 2));
}

int main(){
	double weight, height, BMI;
	cout << "Hello user, welcome to the BMI calculator. Here, you will be able to calculate\n"
		<< "your BMI and see your weight range."
		<< "\n\nPlease enter your weight: ";

	cin >> weight;

	cout << "Please enter your height: ";
	cin >> height;
	BMI = bmiCalc(weight, height);

	cout << endl
		<< "Your BMI is: " << BMI
		<< "\nYour weight range is: ";

	if(18.5<=BMI && BMI<=25){
		cout << "Optimal";
	}

	else if (BMI < 18.5) {
		cout << "Underweight";
	}

	else {
		cout << "Overweight";
	}
}