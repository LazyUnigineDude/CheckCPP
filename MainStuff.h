#pragma once
#include <iostream>
#include <vector>

struct MainStuff {

	MainStuff() {
		std::vector<std::string> Items = {
		"auto, decltype, final, delete, override, nullptr, union, long long, char16_t && char32_t",
		"constexp, noexcept, alignof, alignas, for(auto &i : val)",
		"R value references [ type Obj = &&value ]",
		"Move constructors && Assignment Operators [ &class::operator=(class&& param) ]",
		"Scoped Enum [ enum class Obj : type { value = 10, value2 = 2 }; ]",
		"List Init [ std::list<type> Name = { value, value }; ]",
		"Delegate constructors [ struct S{ S(int x, char y) {} S(int x) : S (x, 'x'){} } ]",
		"Aliases && Templates [ using name = {};  template <typename T> void foo(T t){} ]",
		"Variyadic Templates [ template<typename ...T> void foo(T ...t) {} ]",
		"Literals [ char16_t* x = u\"String\" ]",
		"Attributes [ [[noreturn]] void f() {throw \"error\";} ]",
		"Lambda expressions [ [](){}; ]",
		"Smart Pointers [ std::unique_ptr ]",
		"Multithreading [ std::thread, std::atomic, std::mutex ]\n"
		};


		std::cout << "List of Stuff:\n\n";
		Func(Items);

	}

	void Func(std::vector<std::string> strings) {
		for (auto& i : strings) { std::cout << i << "\n"; }
	}

};