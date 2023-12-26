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

int main() {

	Ex x;
	x.Int(2);

	std::unique_ptr<int> g = std::make_unique<int>(4);

	auto y = X(std::move(g));
	std::cout << "Count: " << y.use_count() << "\n";

	std::vector<int> Vector{ 5, 10, 25, 2, 1350, 13, 24 };
	std::sort(Vector.begin(), Vector.end(), [&](const int& l, const int& r) { return l < r; });
	for (const int& i : Vector) { std::cout << i << " "; }
	std::cout << "\n";

	return 0;
}