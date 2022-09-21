#include <iostream>

// Call a header and use a function;
// #include "OOPCheck.h"
#include <unordered_map>

class Check
{
public:
	Check();
	~Check();
	Check(const char* y, int x) { this->x = x; this->y = y; Map[y] = x; }

	std::unordered_map<const char*, int> Map;

private:
	int x;
	const char* y;

};

Check::Check() : x(0), y("")
{
}

Check::~Check()
{
}


int main() { 

	Check C("HI", 15), D("Hello",2);
	const char* x = "HI";
	std::cout << C.Map[x] << "\n";


	/*
		Arrays
		Lists
		Linked List
		Doubly Linked Lists
		Vector
		Stacks
		Queues
		Hashtables
		Maps
		Graphs
	*/
	// Some example sentence over here  x;  Time = x; Space = 26
	//									    Time =  x + 1; Space = unique letter

	return 0;
}