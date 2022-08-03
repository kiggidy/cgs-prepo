#include <iostream>
#include <thread>
static int HeapInt = 0;
bool quitOut = false;
int threadVar = 0;
void HelloWordThread()
{
    while (!quitOut)
    {
        threadVar++;
        if (threadVar > 1000)
        {
            threadVar = 0;
        }
    }
    std::cout << "Hello World THREAD!\n";
}

int main()
{
    std::cout << "Hello World!\n";
    char userInput;
    std::thread Hello(HelloWordThread);
    
    
    while (!quitOut)
    {
        std::cout << "Press Any Key to display counter" << std::endl;
        std::cout << "Press Q to quit" << std::endl;
        std::cin >> userInput;
        quitOut = (userInput == 'q' || userInput == 'Q');
        std::cout << "Threadvar: " << threadVar << std::endl;
    }

    Hello.join();

    return 0;
}