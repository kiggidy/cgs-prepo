#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Add(T a, T b);

template <typename T>
void DisplayMsg(string message, T number);

void DisplayMsg(string message);


int main()
{
	int i = Add(1, 2);
	float f = Add(3.3f, 2.4f);
	double d = Add(4.4, 6.7);
	DisplayMsg("Testing overload");
	DisplayMsg("Integer Addition = ", i);
	DisplayMsg("Float Addition = ", f);
	DisplayMsg("Double Addition = ", d);
}

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

void DisplayMsg(string message)
{
	cout << message << endl;
}

template <typename T>
void DisplayMsg(string message, T number)
{
	cout << message << number << endl;
}