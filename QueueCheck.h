#pragma once

#include <iostream>
#include <queue>

class QueueCheck
{
private:
	std::queue<int> X;
	
public:
	
	QueueCheck(){
		X.push(6);
		X.push(1);
		X.push(13);
		X.push(41);
		X.push(61);
		X.push(37);
		X.push(6);
	}
	
	void CheckQueue(){
		int x = X.size();
		std::cout << x << "\n";

		for (int i = 0; i < x; i++)
		{
			std::cout << "Number is: " << X.front() << "\n";
			X.pop();
		}
	}
	

};

