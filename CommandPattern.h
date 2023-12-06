#pragma once
// Action into an abstract Order Class

struct Reciever { // PolyMorphism
	int Function1() { return 0; }
	int Function2() { return 1; }
};

struct ICommand {
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

struct Command : ICommand {

	Command(Reciever Reciever) { this->Receiver = &Reciever; }
	void Execute() override { Receiver->Function1(); }
	void Undo() override { Receiver->Function2(); }

	Reciever* Receiver;
};

struct Invoker {

	Invoker(ICommand* Command1,ICommand* Command2) {
		this->Command1 = Command1;
		this->Command2 = Command2;
	}

	void ExecuteOne() { Command1->Execute(); }
	void UndoOne()	  { Command1->Undo(); }
	void ExecuteTwo() { Command2->Execute(); }
	void UndoTwo()	  { Command2->Undo(); }

	ICommand* Command1, *Command2;
};