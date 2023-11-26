#pragma once

struct IObserver {

public:
	IObserver() = default;
	virtual ~IObserver() = 0;
	virtual void Update() = 0;
};


struct IObservable {

public:
	IObservable() = default;
	virtual ~IObservable() = 0;
	virtual void Add(IObserver Observer) = 0;
	virtual void Remove(IObserver Observer) = 0;
	virtual void Notify() = 0;

	virtual void GetState() {}
	virtual void SetState() {}

private:
	IObserver *List[];
};