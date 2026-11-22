#include <iostream>
#include <typeinfo>

class Base
{
	virtual void f() {}
};
class Derived1 : public Base
{
};
class Derived2 : public Base
{
};

int main()
{
	Base *const b = new Derived1();
	Derived1 *const pd = dynamic_cast<Derived1 *>(b);
	std::cout << typeid(*pd).name() << std::endl;
	if (pd != NULL)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}

	try
	{
		Derived1 &rd = dynamic_cast<Derived1 &>(*b);
		std::cout << "OK" << std::endl;
	}
	catch (std::bad_cast &)
	{
		std::cout << "ERROR" << std::endl;
	}

	delete b;
}
