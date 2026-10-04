#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "This is " << "A" << ", detected by pointer" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "This is " << "B" << ", detected by pointer" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "This is " << "C" << ", detected by pointer" << std::endl;
	else
		std::cout << "NOT FOUND" << std::endl;
}
