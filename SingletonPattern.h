#pragma once

struct Singleton {

public:
	Singleton(const Singleton& other) = delete;
	static Singleton* Get() { return &_S; }

private:
	Singleton() {}
	static Singleton _S;
};

Singleton Singleton::_S;

int main() {


	Singleton* S = Singleton::Get();

	return 0;
}