#pragma once

class Abstract {
	
public:
	virtual ~Abstract()		 { }
	virtual void Function1() { }
};

class AbstractDerive : Abstract {

public:
	~AbstractDerive() override { }
	void Function1()  override { }
};



class PureAbstract {

public:
	virtual ~PureAbstract()  = 0;
	virtual void Function1() = 0;
};

PureAbstract::~PureAbstract()  { /* Must Implement */ }
void PureAbstract::Function1() { /* Must Implement */ };

class PureAbstractDerive : PureAbstract {

public:
	~PureAbstractDerive() override { }
	void Function1()	  override { }
};



struct Interface {

public:
	virtual void Function1() = 0;
	virtual void Function2() = 0;
};

struct InterfaceDerive : Interface {

public:
	void Function1() { /* Must Exist */ }
	void Function2() { /* Must Exist */ }
};

int main() {

	AbstractDerive A;
	PureAbstractDerive B;
	InterfaceDerive C;
	 // All work

	return 0;
}