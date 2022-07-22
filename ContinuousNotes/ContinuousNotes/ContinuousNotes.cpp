#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Add(T a, T b);

int main()
{
	cout << "Please enter a positive number: ";
	float firstNumber;
	cin >> firstNumber;
	if (firstNumber > 0)
	{
		cout << "Enter a non 0 number: ";
		float secondNumber;
		cin >> secondNumber;

		if (secondNumber != 0) 
		{
			cout << firstNumber << "/" << secondNumber << " = " << firstNumber / secondNumber << endl;
		}
		else 
		{
			cout << secondNumber << " is 0, GOODBYE" << endl;
		}
	}
	else
	{
		cout << firstNumber << " IS NOT POSITIVE, GOODBYE" << endl;
	}

}
