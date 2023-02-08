#pragma once
#include <iostream>

class UpdatedSmartPointer
{
private:

	int y = 15;

public:

	UpdatedSmartPointer() {

		std::unique_ptr<int> x = std::make_unique<int>(y);

		//			Value Y		Address Y	 Address Y		Address X	  Value Y
		std::cout << y << "  " << &y << "  " << x << "  " << &x << "  " << *x << "\n\n";

		std::shared_ptr<int> shared = std::make_shared<int>(y);
		std::cout << "Out Scope: " << shared.use_count() << "\n";
		{
			std::shared_ptr<int> inScope = shared;
			std::cout << "In Scope: " << inScope.use_count() << "\n";
		}
		std::cout << "Out Scope: " << shared.use_count() << "\n\n";

		std::weak_ptr<int> weak = shared;
		std::cout << "Added Weak: " << shared.use_count() << "\n";
	}

};

