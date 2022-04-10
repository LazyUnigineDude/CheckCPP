#pragma once

#include <map>
#include <string>
#include <iostream>

class MapCheck
{
private:
	std::string test = "Hi, This is a test of frequency of the letters mixed.";
	std::map <char, int> FreqCheck;


public:
	void CheckMap(){
		for (char& c : test)
		{
			//if (FreqCheck.find(c) == FreqCheck.end()) { FreqCheck[c] = 0; }
			if (FreqCheck.count(c) == 0) { FreqCheck[c] = 0; }
			FreqCheck[c]++;
		}

		for (auto& V : FreqCheck)
		{
			printf("Letter: %c  Times: %d \n", V.first, V.second);
		}
	}
	

};

