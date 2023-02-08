#pragma once

#include <iostream>
#include <time.h>
#include <vector>
#include <future>
#include <thread>
#include <mutex>
#include <shared_mutex>

// Prints A 15 times
void F1() {
	for (int i = 0; i < 15; i++)
	{
		std::cout << " A ";
	}
}

// Prints B + x 15 times
void F2(char x) {
	for (int i = 0; i < 15; i++)
	{
		std::cout << " B " << x;
	}
}

// Returns total
int Total(int x, int y) { return x + y; }

struct CheckThread {

	bool operator()(int x, int y) {
		std::cout << "It is: ";
		return  x < y;
	}

	~CheckThread() { delete this; }
};

void MutexLock(int y) {
	std::mutex Mutex;
	Mutex.lock();
	y++;
	std::cout << y;
	Mutex.unlock();
}


class Multithreading
{
public:

	void MainProg();
	void Sender();

private:

	void Worker();
	bool isReady = false, isProcessed = false;
	int Data = 0;
	std::mutex MainMutex;
	std::condition_variable condition;
};

void Multithreading::Sender() {

	std::thread _Worker(&Multithreading::Worker, this);
	
	// Do stuff then send stuff to _Worker
	{	
		std::lock_guard Lock(MainMutex);
		isReady = true;
		std::cout << Data << " Modify and Send to Worker\n";
		Data++;
	}
	condition.notify_one();

	// Waiting Worker
	{
		std::unique_lock Lock(MainMutex);
		condition.wait(Lock, [this /*&*/] {return isProcessed; });
	}
	std::cout << Data << " We Back\n";
	_Worker.join();
}

void Multithreading::Worker() {

	std::unique_lock Lock(MainMutex);
	condition.wait(Lock, [this /*&*/] {return isReady; });

	// Do stuff
	std::cout << Data << " Working With Data\n";
	Data++;

	isProcessed = true;
	// Do stuff
	std::cout << Data << " Finished, Sending Back\n";
	Data++;
	Lock.unlock(); // Must
	condition.notify_one();
}


void Multithreading::MainProg() {

	//srand(time(0));
	//for (int i = 0; i < 10; i++){std::cout << (1 + rand()) % 10 << std::endl;}

	char y = 'y';

	// Vector Threads
	std::vector<std::thread> VThread;
	VThread.push_back(std::thread(F1));

	// Pass by reference
	VThread.push_back(std::thread(std::ref(F2), y));

	for (auto& T : VThread) {
		if (T.joinable())
			T.join();
	}

	// Function Threads
	std::thread Check1(F1);
	std::thread Check2(F2, 'y');
	Check1.join();
	Check2.join();


	// Functor Threads using operator
	//std::unique_ptr<CheckThread> X = std::make_unique<CheckThread>();
	CheckThread* FunctorThread = new CheckThread();
	std::thread FThread(std::ref(*FunctorThread), 5, 3);
	FThread.join();


	// Lambda Threads
	std::thread LambdaCheck([]() {for (int x = 0; x < 15; x++) { std::cout << x << "\n"; }; });
	LambdaCheck.join();

	// ASync
	auto t = std::async(Total, 5, 6);
	std::cout << "Total is: " << t.get() << "\n";


	//Mutex lock and unlock Fnc
	int _y = 0;
	MutexLock(_y);
	std::mutex Mutex;

	//			SMART	LOCKS
	///////////////////////////////////////////////
	{
		// Default Lock/ Unlock via Scope end
		std::lock_guard<std::mutex> LockGuard(Mutex);
		_y++;
	}

	{
		// Choice Lock/ Unlock via Scope end
		std::unique_lock<std::mutex> LockGuard(Mutex);
		_y++;
		LockGuard.unlock();
	}

	//	<shared_mutex>		SHARED	LOCKS
	////////////////////////////////////////////////
	std::shared_mutex MutexShared;
	{
		std::unique_lock<std::shared_mutex> SharedLock(MutexShared);
		_y++;
	}
	{
		std::shared_lock<std::shared_mutex> WatchShared(MutexShared);
		std::cout << _y; // CXX14

	}

	// Deadlock Fix
	///////////////////////////////////////////////
	{
		std::mutex G1, G2;
		std::scoped_lock lock(G1,G2);
	}

}