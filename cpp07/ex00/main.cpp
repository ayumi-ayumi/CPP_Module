#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		int a = 2;
		int b = 3;
		std::cout << "\033[35m" << "Type: int" << "\033[0m" << std::endl;
		std::cout << "Original: " << "a = " << a << ", b = " << b << std::endl;

		::swap(a, b);
		std::cout << "swap():   " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	{
		int a = 8;
		int b = 8;
		std::cout << "\033[35m" << "Type: int - equal value" << "\033[0m" << std::endl;
		std::cout << "Original: " << "a = " << a << ", b = " << b << std::endl;

		::swap(a, b);
		std::cout << "swap():   " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	{
		std::string a = "chaine1";
		std::string b = "chaine2";
		std::cout << "\033[35m" << "Type: string" << "\033[0m" << std::endl;
		std::cout << "Original: " << "a = " << a << ", b = " << b << std::endl;

		::swap(a, b);
		std::cout << "swap():   " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	{
		float a = 2.5;
		float b = 3.5;
		std::cout << "\033[35m" << "Type: float" << "\033[0m" << std::endl;
		std::cout << "Original: " << "a = " << a << ", b = " << b << std::endl;

		::swap(a, b);
		std::cout << "swap():   " << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	return (0);
}
