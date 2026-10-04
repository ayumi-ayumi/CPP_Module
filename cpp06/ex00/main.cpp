#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <str>" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
}
/*
'a'
'0'
1f
2147483647
-2147483648
*/
