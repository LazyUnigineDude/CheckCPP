#include <iostream>
#include <algorithm>
#include "BestPractices.h"
#include <vector>

struct Example {
	Example() { std::cout << "base constructor\n"; }
	virtual ~Example() = 0;
	virtual void Int() = 0;
};
Example::~Example() { std::cout << "base Called\n"; }

struct Ex : Example {
	Ex() { std::cout << "derived Constructor\n"; }
	~Ex() override { std::cout << "derived Called\n"; }
	void Int() override {}
	void Int(int x) { std::cout << " Hello " << x << "\n"; }
};

struct Example2 {
	Example2() { std::cout << "base constructor\n"; }
	~Example2() { std::cout << "base Called\n"; }
};

struct Ex2 : Example2 {
	Ex2() { std::cout << "derived Constructor\n"; }
	~Ex2() { std::cout << "derived Called\n"; }
};

struct BasicStruct {
	BasicStruct() = default;
	BasicStruct(const int& x) { this->x = &x; std::cout << "Created " << &this->x << "\n"; }
	~BasicStruct() { std::cout << "Deleted " << &x <<"\n"; }
	int const* x;
};


int main() {

	//Ex2 x;

	//std::unique_ptr<int> g = std::make_unique<int>(4);

	//auto y = X(std::move(g));
	//std::cout << "Count: " << y.use_count() << "\n";

	//std::vector<int> Vector{ 5, 10, 25, 2, 1350, 13, 24 };
	//std::sort(Vector.begin(), Vector.end(), [&](const int& l, const int& r) { return l < r; });
	//for (const int& i : Vector) { std::cout << i << " "; }
	//std::cout << "\n";

	BasicStruct S = BasicStruct(2);
	S = BasicStruct(3);

	return 0;
}