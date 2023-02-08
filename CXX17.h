#pragma once
#include <iostream>
#include <vector>

struct CXX17 {

	CXX17() {
		std::vector<std::string> Items = {
			"Lambda *this Capture [ auto x = [this](){}; ]"
			"Compile if constexpr [ if constexpr (true) {} else {}; ]",
			"Initializer if statement [ if(int x = 5; x < var){} ]",
			"Constexpr Lambda [ int x = [](int v){}; constexpr int y = x(2); ]",
			"Inline KeyWorld [ inline void Fnc(){}; ]",
			"Structured Bindings [ struct S { int x, y; }; int main(){ auto [x,y] = S {1,2}; } ]",
			"Temporary materialization [ struct S {int x; };  int main(){ int y = S().x; }]",
			"Class Template Argument Deduction [ template <typename T> Struct S{ S(T,T); }; auto z = A{1,2}; ]",			
			"Fold Expressions [ void Func(int ...p){ (p + ...); } ]",
			"Auto Specifier for Templates [ template<auto T> ]",
			"Attributes update: nodiscard, fallthrough, maybe_unused",
			"Attribute listing [ [[using class: Att1, Att2 ]] ]"
		};

		std::cout << "List of Stuff:\n\n";
		Func(Items);
	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};