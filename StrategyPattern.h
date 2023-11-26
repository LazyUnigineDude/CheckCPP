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


struct StrategyPattern {

public:
	
	StrategyPattern(IBehaviour* Object) {
		this->Object = Object;
	}

private:
	IBehaviour* Object;
};