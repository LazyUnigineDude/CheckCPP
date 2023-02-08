#pragma once
#include <iostream>
#include <functional>

void PrintNum(int num) { std::cout << "Function Argument " << num << "\n"; }
void Func1() { std::cout << "Running this Function \n"; }

struct AdvFunctions {

	void Callback(int num) {
		// function pointer

		PrintVoid(Func1);

		// Lamda Call with num Capture
		auto x = [num]() {std::cout << "Lambda Function " << num << "\n"; };
		x();

		// Lamda Call as std::function<void(int)> argument
		PrintNumber(num, [](int value) { std::cout << "Function Lambda Argument " << value << "\n"; }); \
		PrintNumber(num, PrintNum);
		
		// Callback Functions from within class;
		std::function<void(int)> Func = std::bind(&AdvFunctions::Print, this, num);
		Func(num);
	}
	
private:
	
	void Print(int num) { std::cout << num << "\n"; }
	void PrintVoid(std::function<void()> Func) { Func(); }
	void PrintNumber(int num, std::function<void(int)> Func) { Func(num); }
};