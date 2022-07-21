#include <iostream>
#include <string>

using namespace std;

void DisplayMsg(string message);
int g_yearinput;
void LeapYearCheck(int y);

int main()
{
    DisplayMsg("Input a year and we will tell you whether it is a leap year. Hit ENTER at the end.");
    cin >> g_yearinput;
    LeapYearCheck(g_yearinput);
}

//if it is divisible by 4 and not 100 it is a leap year
void LeapYearCheck(int y)
{
    bool isDivisibleByFour = ((y % 4) == 0); //True when divisible by four, is a leap year
    bool isDivisibleByHundred = ((y % 100) == 0); //True when divisible by 100, is not a leap year
    bool isDivisibleByFourHundred = ((y % 400) == 0); //True when divisible by four hundred, is a leap year
    if ((isDivisibleByFour && !isDivisibleByHundred) || isDivisibleByFourHundred)
    {
        DisplayMsg("Yes, this is a leap year.");
    }
    else
    {
        DisplayMsg("No, this is not a leap year.");
    }
}

void DisplayMsg(string message)
{
    cout << message << endl;
}
