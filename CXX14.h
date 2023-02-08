#pragma once
#include <iostream>
#include <vector>

struct CXX14 {

	CXX14() {
		std::vector<std::string> Items = {
			"Variable Templates [ template<class T> T obj = var; ]",
			"Generic Lambda Capture clauses [ auto x = [/*&*/ var /*=*/](){}; ]",
			"Binary Literals [ 0x2a, 0b10010 ]",
			"Make Smart Pointer [ std::unique_ptr<type> var = std::make_unique<type>(value); ]",
			"Shared_Lock for Multithreading [ std::shared_lock<std::shared_mutex> Lock(Mutex) ]",
			"Aggregate Classes [ class Foo{int x, y, z[2]; }; int main(){ Foo x = {1, 2 , {3,4} }; } ]"
		};

		std::cout << "List of Stuff:\n\n";
		Func(Items);
	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};