#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Challenge 1 - Take in 3 numbers and return the average and sum.
	// Prompt user for three numbers
	cout << "For a Sum and Average, please input 3 numbers, separated by hitting ENTER.\n";
	// Get the Numbers
	float firstNum;
	float secondNum;
	float thirdNum;
	cin >> firstNum >> secondNum >> thirdNum;
	// Calculate the sum
	float sumTotal = firstNum + secondNum + thirdNum;
	// Calculate the avg
	float avg = sumTotal / 3;

	cout << "Value 1 = " << firstNum << endl << " Value 2 = " << secondNum << endl << " Value 3 = " << thirdNum << endl;
	cout << "Sum total = " << sumTotal << endl << "Average = " << avg;
}
