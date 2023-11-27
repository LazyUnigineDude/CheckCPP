#pragma once
#include <iostream>

struct IBehaviour {

public:
	IBehaviour() = default;
	virtual void Execute() = 0;
};

struct NewBehaviourA : IBehaviour {

public:
	NewBehaviourA() {}
	void Execute() override { std::cout << "Execution 1\n"; }
};


struct NewBehaviourB : IBehaviour {

public:
	NewBehaviourB() {}
	void Execute() override { std::cout << "Execution 2\n"; }
};


struct Strategy {

public:
	
	Strategy(IBehaviour* Object) {
		this->Object = Object;
	}

	void Execute() { Object->Execute(); }

private:
	IBehaviour* Object;
};

int main() {


	NewBehaviourA A;
	NewBehaviourB B;

	Strategy S1 = Strategy(&A);
	Strategy S2 = Strategy(&B);

	S1.Execute();
	S2.Execute();

	return 0;
}