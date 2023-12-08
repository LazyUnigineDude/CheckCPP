#pragma once
// Adapter/Wrapper Pattern. Change way to use it instead of changing it

struct Adaptee {
	void SpecificRequest() { }
};

struct ITarget {
	virtual void Request() = 0;
};

class Adapter : ITarget {
public:

	Adapter(Adaptee& Adaptee) {
		this->Adaptee = Adaptee;
	}

	void Request() override {
		Adaptee.SpecificRequest();
		// Whatever Else
	}

private:
	Adaptee Adaptee;
};

int main() {
	
	Adaptee B;
	Adapter A(B);
	A.Request();

	return 0;
}