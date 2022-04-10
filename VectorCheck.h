#pragma once

#include <vector>
#include <iostream>

class VectorCheck
{
private:
	std::vector<int> X{4,5,5,6,6,7,4,37,3,558,564};
	
public:

	void CheckVector(){
		for (int& x : X)
		{
			std::cout << x << "\n";
		}
		std::cout << X[6];
	}
	
	std::vector<int> productExceptSelf(std::vector<int>& nums) {


	std::vector<int> res = nums;
	int postfix = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		res[i] *= res[i - 1];
	}

	for (int i = nums.size() - 1; i > 0; --i)
	{
		res[i] = postfix;
		res[i] *= res[i - 1];
		postfix *= nums[i];
	}
	res[0] = postfix;

	return res;

}

};

