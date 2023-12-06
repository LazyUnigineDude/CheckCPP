#pragma once
#include <iostream>

struct Base {
	
public:
	virtual int GetValue() = 0;

};

class Derived : public Base {

public:
	int GetValue() override { return 1; }
};

struct IDecorator : public Base {

public:
	virtual int GetValue() = 0;
};

struct IIDecorator1 : public IDecorator {

public:
	IIDecorator1(Base* Base) { this->Base = Base; }
	int GetValue() override { return Base->GetValue() + 1; }

protected:
	Base* Base;
};

struct IIDecorator2 : public IDecorator {

public:
	IIDecorator2(Base* Base) { this->Base = Base; }
	int GetValue() override { return Base->GetValue() + 2; }

protected:
	Base* Base;
};



int main() {

	Derived A;
	IIDecorator1 B = IIDecorator1(&A);
	IIDecorator2 C = IIDecorator2(&A);

	std::cout << "Main Value of A: " << A.GetValue() << "\n";
	std::cout << "Main Value of B: " << B.GetValue() << "\n";
	std::cout << "Main Value of C: " << C.GetValue() << "\n";

	return 0;
}