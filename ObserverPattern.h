#pragma once
#include <set>

struct IObserver { //Subscriber to Notification

public:
	virtual void Update() = 0;
	virtual void Display() = 0;
};


struct IObservable { //Notifier

public:
	virtual void Add(IObserver* Observer) = 0;
	virtual void Remove(IObserver* Observer) = 0;
	virtual void Notify() = 0;

	virtual int GetValue() = 0;
};

struct Observer1 : public IObserver {
public:
	Observer1(IObservable* Observable) { this->Observable = Observable; }
	~Observer1() {}

	void Update() override { Var = Observable->GetValue(); Display(); }
	void Display() { std::cout << "Var1: " << Var << "\n"; }

private:
	int Var = 0;
	IObservable* Observable;
};

struct Observer2 : public IObserver {
public:
	Observer2(IObservable* Observable) { this->Observable = Observable; Observable->Add(this); }
	~Observer2() {}

	void Update() override { Var = Observable->GetValue() + 2; Display(); }
	void Display() { std::cout << "Var2: " << Var << "\n"; }

private:
	int Var = 0;
	IObservable* Observable;
};

struct Observable : public IObservable {

public:
	Observable() = default;
	~Observable() {}

	void Add(IObserver* Observer) override { List.insert(Observer); }
	void Remove(IObserver* Observer) override { List.erase(Observer); }
	void Notify() override { for (auto& Obj : List) { Obj->Update(); } }

	int GetValue() override { return Var; }

private:
	std::set<IObserver*> List;
	int Var = 10;
};


int main() {

	Observable _Observable;
	_Observable = Observable();

	Observer1 A = Observer1(&_Observable);
	Observer2 B = Observer2(&_Observable);

	_Observable.Add(&A);

	A.Display();
	B.Display();
	std::cout << "\n\nNotification\n";

	_Observable.Notify();
	return 0;
}