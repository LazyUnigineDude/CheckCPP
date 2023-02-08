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

		std::unique_ptr<int> x = std::make_unique<int>(y); // make_unique CXX14
		//int y = 10;
		//int* x = &y;

		//			Value Y		Address Y	 Address Y		Address X	  Value Y
		 std::cout << y << "  " << &y << "  " << x << "  " << &x << "  " << *x << "\n\n";

		 std::shared_ptr<int> shared = std::make_shared<int>(y);// make_shared CXX14
		 std::cout << "Out Scope: " << shared.use_count() << "\n";
		 {
			 std::shared_ptr<int> inScope = shared;
			 std::cout << "In Scope: " << inScope.use_count() << "\n";
		 }
		 std::cout << "Out Scope: " << shared.use_count() << "\n\n";

		 std::weak_ptr<int> weak = shared;
		 std::cout << "Added Weak: " << shared.use_count() << "\n";
	}

};

