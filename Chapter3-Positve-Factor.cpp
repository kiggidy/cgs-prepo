#include <iostream>
#include <string>

using namespace std;

void InputValidate(int v);
void FactorInput(int v);
int g_inputNum;

int main()
{
	cout << "Input a positive number to get the factor of: " << endl;
	cin >> g_inputNum;
	InputValidate(g_inputNum);
}

void InputValidate(int v)
{
	if (v > 0)
	{
		FactorInput(v);
	}
	else
	{
		do
		{
			cout << "That was not a positive number, please input a positive number: " << endl;
			cin >> v;

		} while (!(v > 0));
		FactorInput(v);
	}
}

void FactorInput(int v) 
{
	for (int i = 1; i <= v; i++)
	{
		if (v % i == 0)
		{
			cout << i << " x " << v / i << ", ";
		}
	}
}
