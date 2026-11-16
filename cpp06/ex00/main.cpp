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
.f
0.f

2147483647
char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0

-2147483648
char: impossible
int: -2147483648
float: -2147483648.0f
double: -2147483648.0

2147483648
char: impossible
int: impossible
float: 2147483648.0f
double: 2147483648.0

-2147483649
char: impossible
int: impossible
float: -2147483648.0f
double: -2147483649.0
*/
