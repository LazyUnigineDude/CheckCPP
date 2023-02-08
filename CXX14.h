#pragma once
#include <iostream>
#include <vector>

struct CXX14 {

	CXX14() {
		std::vector<std::string> Items = {
		"Variable Templates [ template<class T> T obj = var; ]",
		"Generic Lambda + Capture [ auto x = [/*&*/ this /*=*/](){}; ]",
		"Binary Literals [ 0x2a, 0b10010 ]",
		"Make uniques [ std::unique_ptr<type> var = std::make_unique<type>(value); ]",
		"Shared_Lock"
		};

		std::cout << "List of Stuff:\n\n";
		Func(Items);
	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};