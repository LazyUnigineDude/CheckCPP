#pragma once
#include <functional>
#include <iostream>
#include <string>

template <class T>
T Add(T a, T b) { return a + b; }

class SmartPCheck
{
private:

	int y = 15;

public:

    void CheckPointer() {

		std::unique_ptr<int> x = std::make_unique<int>(y);
		//int y = 10;
		//int* x = &y;

		//			Value Y		Address Y	 Address Y		Address X	  Value Y
		 std::cout << y << "  " << &y << "  " << x << "  " << &x << "  " << *x;
	}

	void Release(const std::function<std::string()> &X) { std::cout << X(); }
	std::string MakeMe() { return "NEVAAA"; }

	// Function Pointers of different type  ew.
	int SumNum(int (*FncName)(int), int x) { return FncName(x) + x; }

	int SumNum(const std::function<int(int)> &NumFnc, int Num1) { return (NumFnc(Num1) + Num1); }
	int DoubleNum(int Num1) { return Num1 * Num1; }

};

