#pragma once
#include <string>
#include <iostream>

template<typename T>
void Swap(T& first, T& second)
{
	std::cout << first << "  " << second;

	T _T = first;
	first = second;
	second = _T;

	std::cout << first << "  " << second;
}


class OOPCheck
{
public:
	OOPCheck() {

		BasicID ID1 = BasicID("John", "ABC", 1242);
		HigherID ID2 = HigherID(ID1, "Dude", "Earth");

		ID1.CHECKID();
		ID2.CHECKID();
	}
};


class IDCHECKUP {
	virtual void CHECKID() = 0;
};

class BasicID : IDCHECKUP {

private:
	std::string Name;
	std::string Company;
	int ID;

public:

	BasicID(std::string Name, std::string Company, int ID){

		this->Name = Name;
		this->Company = Company;
		this->ID = ID;

	}
	void getFull() { std::cout << "Name: " << this->Name << "  Company: " << this->Company << std::endl; }
	void CHECKID() { std::cout << "ID is: " << ID << std::endl; }
};

class HigherID : BasicID {

private:
	std::string Occupation;
	std::string Location;
	BasicID* ID;

public:

	HigherID(BasicID &ID, std::string Occupation, std::string Location) : BasicID(ID){

		this->Occupation = Occupation;
		this->Location = Location;
		this->ID = &ID;

	}

	void getFull() { std::cout << "Occupation: " << Occupation << "  Location: " << Location << std::endl; }
	void CHECKID() { std::cout << "FUll DATA: " << ID << std::endl; ID->CHECKID() ; ID->getFull(); getFull(); }


};