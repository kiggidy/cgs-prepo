// Chapter3_Algorithms_Challenge_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <chrono>

void FillArray(int fillArr[], int arrSize);
void CountingSort(int sortArr[], int arrSize);
void DisplayArray(int arr[], int arrSize);
void BubbleSort(int sortArr[], int arrSize);

int main()
{
	srand(time(NULL));
	int arraySize = rand() % 10; //set varying array size
	int *randArray = new int[arraySize]; 
	FillArray(randArray, arraySize);
	std::cout << "Array generated: " << std::endl;
	DisplayArray(randArray, arraySize);
	auto start = std::chrono::steady_clock::now();
	BubbleSort(randArray, arraySize);
	//CountingSort(randArray, arraySize);
	auto end = std::chrono::steady_clock::now();
	std::cout << "Elapsed time in milliseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
	std::cout << "Elapsed time in seconds: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " sec" << std::endl;
	std::cout << "Array sorted: " << std::endl;
	DisplayArray(randArray, arraySize);
	delete randArray;
}

void DisplayArray(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void FillArray(int fillArr[], int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		fillArr[i] = rand() % arrSize - 1;
	}
}

void BubbleSort(int sortArr[], int arrSize)
{
	bool exchange;
	do {
		exchange = false;
		for (int i = 0; i < arrSize - 1 ; i++)
		{
			if (sortArr[i] > sortArr[i + 1])
			{
				double temp = sortArr[i];
				sortArr[i] = sortArr[i + 1];
				sortArr[i + 1] = temp;
			}
		}
	} while (exchange);
	
}

//void CountingSort(int sortArr[], int arrSize)
//{
//	int* tempArr = new int[arrSize];
//	int* countArr = new int[arrSize];
//	int max = sortArr[0];
//	for (int i = 0; i < arrSize; i++)
//	{
//		if (sortArr[i] > max)
//		{
//			max = sortArr[i];
//		}
//	}
//
//	for (int i = 0; i <= max; ++i)
//	{
//		countArr[i] = 0;
//	}
//
//	for (int i = 0; i < arrSize; i++)
//	{
//		countArr[sortArr[i]]++;
//	}
//	
//	for (int i = 1; i <= max; i++)
//	{
//		countArr[i] += countArr[i - 1];
//	}
//	
//	for (int i = arrSize - 1; i >= 0; i--)
//	{
//		tempArr[countArr[sortArr[i] - 1]] = sortArr[i];
//		countArr[sortArr[i]]--;
//	}
//	
//	for (int i = 0; i < arrSize; i++) {
//		sortArr[i] = tempArr[i];
//	}
//}

