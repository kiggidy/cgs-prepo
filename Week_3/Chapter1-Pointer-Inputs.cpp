#include <iostream>
#include <string>

using namespace std;
void GetInputVariables(int a, int b);
void DisplayInputsByPointer(int a, int b);

int main()
{
	int a;
	int b;

	cout << "Input an integer, please: ";
	cin >> a;
	cout << "\n Input a second integer, please: ";
	cin >> b;
	DisplayInputsByPointer(a, b);
}

void DisplayInputsByPointer(int a, int b)
{
	int* ptrA = &a;
	int* ptrB = &b;

	cout << "You input " << *ptrA << " first and " << *ptrB << " second!" << endl;
}
