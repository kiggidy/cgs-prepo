#include <iostream>
#include <thread>
static int HeapInt = 0;
bool ShouldEndThread = false;
void HelloWordThread()
{
    int threadVar = 0;
    while (!ShouldEndThread)
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
    HeapInt = 8;
    std::cout << "Hello World!\n";
    std::thread Hello(HelloWordThread);
    Hello.join();
    return 0;
}