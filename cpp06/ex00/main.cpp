#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "Usage: ./convert <str>" << std::endl;
	ScalarConverter scalar;
	scalar.convert(argv[1]);
}