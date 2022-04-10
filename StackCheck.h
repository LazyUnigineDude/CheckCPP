#pragma once

#include <string>
#include <stack>
#include <iostream>

class StackCheck
{
private:
	std::string X = "Hi, My Name is Omar!";
	std::stack<char> C;


public:
	void CheckStack() {
		std::cout << X << "\n";
		for (const char& c : X) { C.push(c); }
		//for (char& c : X) { X[c] = C.top(); C.pop(); } Doesn't work
		for (int i = 0; i < X.length(); i++) { X[i] = C.top(); C.pop(); }
		std::cout << X << "\n";
	}

};

