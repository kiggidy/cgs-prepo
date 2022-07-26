#include <iostream>
#include <string>

using namespace std;


//dataType* userIdentifier = someAddress;
// 


int main()
{
	bool isPlayerAlive = true;
	bool isGameOver = false;
	//Change Pointer Addresses
	bool* pToBool = &isPlayerAlive; // pToBool points to the address of isPlayerAlive
	pToBool = &isGameOver; // pToBool now points to the address of isGameOVer
	pToBool = nullptr; //pToBool points to nothing, no memory address now - it is dereferenced?

	//Access Stored values
	int var = 10;
	//pointers only store addresses
	int* ptr = &var;
	//dereference the pointer, this gets the value of it
	int newVar = *ptr; // ~= newVar = 10, this would update if we update var
	//derefence ptr and store 20 
	*ptr = 20; //var is now also 20
	//You cannot access a value with a nullptr - it doesn't point to anything, 
	//derefencing will give an exception

	//good practice to set an if statement to check that ptr != Null

}