#include <iostream>
#include <string>

using namespace std;


void PopulateArray(float theArray[], int size);
float GetLargestNumber(float theArray[], int size);
void DisplayArray(float theArray[], int size);


int main()
{
	constexpr int kSize = 5;
	float inputArray[kSize];
	cout << "Please input 5 numbers: " << endl;
	PopulateArray(inputArray, kSize);
	cout << "You have input: ";
	DisplayArray(inputArray, kSize);
	cout << "The largest number in the array: " << GetLargestNumber(inputArray, kSize);
}


void PopulateArray(float theArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> theArray[i];
	}
}


float GetLargestNumber(float theArray[], int size)
{
	int largestVal = theArray[0];
	for (int i = 0; i < size; i++)
	{
		if (theArray[i] > largestVal)
		{
			largestVal = theArray[i];
		}
		else
		{
			continue;
		}
	}
	return largestVal;
}

void DisplayArray(float theArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << theArray[i] << " ";
	}
}