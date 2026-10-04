#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "This is " << "A" << ", detected by reference" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "This is " << "B" << ", detected by reference" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "This is " << "C" << ", detected by reference" << std::endl;
		return ;
	}
	catch(...)
	{
		std::cerr << "NOT FOUND" << '\n';
	}
}
