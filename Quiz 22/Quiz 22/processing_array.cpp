// This program reads data from a file into an array.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int ARRAY_SIZE = 100; // Array size
	int numbers[ARRAY_SIZE];   // Array with 10 elements
	int count = 0, sum=0, highest, lowest;             // Loop counter variable
	ifstream inputFile("C:\\Users\\User\\source\\repos\\C-\\Quiz 22\\numbers.txt");        // Input file stream object
	
	// Read the numbers from the file into the array.


		while (count < ARRAY_SIZE && inputFile >> numbers[count]) {
			if (count == 0)
				lowest = highest = numbers[0];

			sum += numbers[count];

			if (lowest > numbers[count])
				lowest = numbers[count];
		

			else if (highest < numbers[count])
				highest = numbers[count];

			count++;
		}

	



	// Close the file.
	inputFile.close();
	
	// Display the numbers read:
	if (count > 0) {
		cout << "The numbers are: ";
		for (int i = 0; i < count; i++)
			cout << numbers[i] << " ";

		cout << endl << "The sum of all the numbers is " << sum
			<< ".\nThe average is " << static_cast<double>(sum) / count
			<< ".\nThe highest and lowest values are " << highest << " and " << lowest << ".\n";
	}
	
	else {
		cout << "\nThere are no values in the given file or the file cannot be found.";
	}
	cout << endl;
	system("pause");
	return 0;
}