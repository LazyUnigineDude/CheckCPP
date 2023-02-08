#pragma once
#include <iostream>
#include <vector>


struct CXX20 {

	CXX20() {
		std::vector<std::string> Items = {
			"consteval, constinit expressions",
			"3 Way Comparison Operator (SpaceShip Operator) [ <=> ]",
			"Default Equal Operator[ operator==() = default ]",
			"Designated Inits [ struct S{int x, y, z}; S obj{ .x = 1, .z = 2 /*.y auto 0*/ }; ]",
			"Ranged For init clause [ for(int x = 0; auto &i : obj){} ]",
			"Attributes: no_unique_address, likely, unlikely",
			"Packs in Lambda capture templates [ auto x = []<typename ...T>(T ...t){}; ]",
			"Coroutines (co_await, co_yeild, co_return) [ Coroutines.h for more info... ]",
			"Modules [ export module projname; import <iostream>; export void fnc(){} ||| import projname; int main(){fnc();} ]",
			"Concepts and Constraints [ Concepts.h for more info... ]",
			"Abbreviated templates [ void func(auto); /*same as template<class T>void func(T)*/ ]",
		};

		std::cout << "List of Stuff:\n\n";
		Func(Items);
	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};