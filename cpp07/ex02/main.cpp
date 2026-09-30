#include "Array.hpp"
#include <iostream>

int main()
{
	// 1. Empty Array
	std::cout << "===== Empty Array =====" << std::endl;
	Array<int> empty;

	std::cout << "size: " << empty.size() << std::endl;


	// 2. Array with size
	std::cout << "\n===== Array with size =====" << std::endl;
	Array<int> a(5);

	std::cout << "size: " << a.size() << std::endl;

	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "a[1]: " << a[1] << std::endl;


	// 3. Access and modify elements
	std::cout << "\n===== Modify elements =====" << std::endl;

	a[0] = 10;
	a[1] = 20;
	a[2] = 30;

	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "a[1]: " << a[1] << std::endl;
	std::cout << "a[2]: " << a[2] << std::endl;


	// 4. Out of bounds
	std::cout << "\n===== Out of bounds =====" << std::endl;

	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	// 5. Copy constructor
	std::cout << "\n===== Copy constructor =====" << std::endl;

	Array<int> b(a);

	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;

	b[0] = 999;

	std::cout << "After changing b[0]:" << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;


	// 6. Assignment operator
	std::cout << "\n===== Assignment operator =====" << std::endl;

	Array<int> c(2);

	c[0] = 100;
	c[1] = 200;

	std::cout << "Before assignment:" << std::endl;
	std::cout << "c.size(): " << c.size() << std::endl;

	c = a;

	std::cout << "After c = a:" << std::endl;
	std::cout << "c.size(): " << c.size() << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;
	std::cout << "c[1]: " << c[1] << std::endl;

	c[0] = 777;

	std::cout << "After changing c[0]:" << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;

	return 0;
}
