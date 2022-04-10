#pragma once

#include <iostream>
#include <thread>

class MultithreadCheck
{
private:




public:

	MultithreadCheck(){
	}

	void F1() {
		for (int i = 0; i < 15; i++)
		{
			std::cout << " A ";
		}
	}
	void F2(char x) {
		for (int i = 0; i < 15; i++)
		{
			std::cout << " B " << x;
		}
	}

};

