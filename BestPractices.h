#pragma once
#include <memory>

// Philosophy
// Easy Typing Easy Reading

void ClearFunctionNameExpressingAction(int ClearName) {  }

/*
* IN
	Func(X);  Cheap/Impossible to Copy  - Retain Copy
	Func(const X&); Cheap Copy/Expensive to Move - Retain Copy

	Func(X&&); Cheap Move

* IN/OUT
	Func(X&); Cheap Copy and Expensive Move

* OUT
	X Func();  Cheap Copy
	Func(X&);	Expensive Move

*/

/*
	Func(Val); Independent Owner of Resource
	Func(Val*); Borrowed Resource
	Func(Val&); Borrowed Resource
	Func(std::unique_ptr); Independent Owner
	Func(std::shared_ptr); Shared Owner
*/

std::shared_ptr<int> X(std::unique_ptr<int> x) { return std::make_shared<int>(*x); }
//std::shared_ptr<int> y = X(std::move(g));
//std::cout << "Count: " << y.use_count() << "\n";