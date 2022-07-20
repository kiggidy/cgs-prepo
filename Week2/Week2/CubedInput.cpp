#include <iostream>
#include <string>

using namespace std;

void printMessage(string message);
int cubed(int cubeIn);

int main()
{
	// Challenge 2 - write a program that returns the value of an input, cubed.
	// Prompt for the number
	printMessage("Input number that you would like cubed.\n");
	// Get the Number
	int cubeIn;
	cin >> cubeIn;
	int r = cubed(cubeIn);
	cout << cubeIn << "^ 3 = " << r << endl;
}
void printMessage(string message)
{
	cout << message << endl;
}

int cubed(int cubeIn)
{
	return cubeIn * cubeIn * cubeIn;
}