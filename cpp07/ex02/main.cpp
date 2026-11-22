#include "Array.hpp"
#include <iostream>

int main()
{
	{ // 1. Empty Array
		std::cout << "\033[35m" << "===== Empty Array =====" << "\033[0m" << std::endl;

		Array<int> empty;
		std::cout << "size: " << empty.size() << std::endl;

		try
		{
			std::cout << empty[0] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// 2. Array with size
	std::cout << "\033[35m" << "\n===== Array with size =====" << "\033[0m" << std::endl;

	Array<int> a(5);
	std::cout << "size: " << a.size() << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "a[1]: " << a[1] << std::endl;

	// 3. Access and modify elements
	std::cout << "\033[35m" << "\n===== Modify elements =====" << "\033[0m" << std::endl;

	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "a[1]: " << a[1] << std::endl;
	std::cout << "a[2]: " << a[2] << std::endl;

	// 4. Out of bounds
	std::cout << "\033[35m" << "\n===== Out of bounds =====" << "\033[0m" << std::endl;

	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// 5. Copy constructor
	std::cout << "\033[35m" << "\n===== Copy constructor =====" << "\033[0m" << std::endl;

	Array<int> b(a);
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;

	b[0] = 999;
	std::cout << "\033[33m" << "After changing b[0]:" << "\033[0m" << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;

	// 6. Assignment operator
	std::cout << "\033[35m" << "\n===== Assignment operator =====" << "\033[0m" << std::endl;

	Array<int> c(2);
	c[0] = 100;
	c[1] = 200;
	std::cout << "\033[33m" << "Before assignment:" << "\033[0m"  << std::endl;
	std::cout << "c.size(): " << c.size() << std::endl;

	c = a;
	std::cout << "\033[33m" << "After c = a:" << "\033[0m" << std::endl;
	std::cout << "c.size(): " << c.size() << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;
	std::cout << "c[1]: " << c[1] << std::endl;

	c[0] = 777;
	std::cout << "\033[33m" << "After changing c[0]:" << "\033[0m" << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;

	return 0;
}
