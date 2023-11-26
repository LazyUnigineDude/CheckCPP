#pragma once


struct IBehaviour {

public:
	IBehaviour() = default;
	virtual ~IBehaviour() = 0;
	virtual void Execute() = 0;
};

struct NewBehaviourA : IBehaviour {

public:
	NewBehaviourA() {}
	~NewBehaviourA() override {}
	void Execute() override {}
};


struct NewBehaviourB : IBehaviour {

public:
	NewBehaviourB() {}
	~NewBehaviourB() override {}
	void Execute() override {}
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

void main() {


	NewBehaviourA A;
	NewBehaviourB B;

	Strategy *S1, *S2;

	S1 = new Strategy(&A);
	S2 = new Strategy(&B);

	S1->Execute();
	S2->Execute();
}