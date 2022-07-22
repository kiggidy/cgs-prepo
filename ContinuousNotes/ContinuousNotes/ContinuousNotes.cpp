#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Add(T a, T b);

int main()
{
	cout << "Please choose an option: " << endl;
	cout << "A Check if even : " << endl;
	cout << "B Check if positive: " << endl;
	cout << "C Check if multiple of 7: " << endl;
	cout << "Input a, b, or c: ";
	int input;
	cin >> input;

	switch (input)
	{
		case 'a':
		case 'A':
		{
			cout << "Please enter the number to check" << endl;
			int checkNum;
			cin >> checkNum;

			if (checkNum % 2 == 0)
			{
				cout << checkNum << " is even!" << endl;
			}
			else if (checkNum == 0)
			{
				cout << checkNum << " is 0!" << endl;
			}
			else
			{
				cout << checkNum << " is odd!" << endl;
			}
			break;
		}
		case 'b':
		case 'B':
		{
			cout << "Please enter the number to check" << endl;
			int checkNum;
			cin >> checkNum;

			if (checkNum > 0)
			{
				cout << checkNum << " is positive!" << endl;
			}
			else if (checkNum == 0)
			{
				cout << checkNum << " is 0!" << endl;
			}
			else
			{
				cout << checkNum << " is negative!" << endl;
			}
			break;
		}
		case 'c':
		case 'C':
		{
			cout << "Please enter the number to check" << endl;
			int checkNum;
			cin >> checkNum;

			bool isMultipleOf7 = checkNum % 7 == 0;
			if (isMultipleOf7)
			{
				cout << checkNum << " is a multiple of 7!" << endl;
			}
			else
			{
				cout << checkNum << " is not a multiple of 7!" << endl;
			}

			break;
		}
		default:
		{
			cout << "Invalid option selected, goodbye" << endl;
			break;
		}
	}
}

