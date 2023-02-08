#pragma once
#include <iostream>
#include <vector>


struct CXX20 {

	CXX20() {
		std::vector<std::string> Items = {
			" "
		};

		std::cout << "List of Stuff:\n\n";
		Func(Items);
	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};