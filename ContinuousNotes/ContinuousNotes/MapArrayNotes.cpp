#include <iostream>
#include <string>

using namespace std;


constexpr int kHeight = 5;
constexpr int kWidth = 6;

void DisplayMap(char map[kHeight][kWidth]);
void Display1dMap(char map[], int width, int height);
int GetIndexFromXY(int x, int y, int width);

int main()
{
	char myMap[kHeight][kWidth] = { {'+','-','-','-','+'},
								   {'|','@',' ',' ','|'},
								   {'|',' ',' ',' ','|'},
								   {'|',' ',' ','X','|'},
								   {'+','-','-','-','+'}
	};
	DisplayMap(myMap);

	char my1dMap[] = { '+','-','-','-','+',
					   '|','@',' ',' ','|',
					   '|',' ',' ',' ','|',
					   '|',' ',' ','X','|',
					   '+','-','-','-','+'
	};
	Display1dMap(my1dMap, kHeight, kWidth);
}

void DisplayMap(char map[kHeight][kWidth])
{
	for (int y = 0; y < kHeight; y++)
	{
		for (int x = 0; x < kWidth; x++)
		{
			cout << map[y][x];
		}
		cout << endl;
	}
}

int GetIndexFromXY(int x, int y, int width) 
{
	return x + y * width;
}


void Display1dMap(char map[], int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int index = GetIndexFromXY(x, y, width);
			cout << map[index];
		}
		cout << endl;
	}
}