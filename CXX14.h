#pragma once
#include <iostream>
#include <vector>

struct CXX14 {

	CXX14() {
		std::vector<std::string> Items = {
		"Variable Templates [ ]",
		"constexp, noexcept, alignof, alignas, for(auto &i : val)"
		};

		std::cout << "List of Stuff:\n\n";
		Func(Items);
	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};