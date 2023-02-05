#pragma once
#include <iostream>



struct CheckOrder {

class Vehicle { public: ~Vehicle() { std::cout << "Vehicle\n"; } };
class Engine { public: ~Engine() { std::cout << "Engine\n"; } };
class Truck : Vehicle { public: ~Truck() { std::cout << "Truck\n"; } private: Engine e; };

	 CheckOrder() {
		 Truck Truck;
	}
};