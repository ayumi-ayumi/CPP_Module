#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

enum Type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NAN,
	NANF,
	INF,
	INFF,
	INVALID
};

bool isInt(const std::string &str)
{
	int i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

int detectType(const std::string &str, int &isNegative)
{
	if (str[0] == '-')
		isNegative = 1;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (CHAR);
	else if (str == "nan")
		return (NAN);
	else if (str == "nanf")
		return (NANF);
	else if (str[str.length() - 1] == 'f')
		return (FLOAT);
	else if (str[str.length() - 2] == '.')
		return (DOUBLE);
	else if (isInt(str))
		return (INT);
	else
		return (INVALID);
}

void ScalarConverter::convert(const std::string &str)
{
	int isNegative;
	int type = detectType(str, isNegative);
	
	if (type == INVALID)
	{
		std::cout << "Invalid input, it cannot be detected" << std::endl;
		return;
	}
	if (type == FLOAT)
	{
		// float a = stoll(str);
		std::cout << std::numeric_limits<float>::min() << std::endl;
		if (static_cast<float>(stoll(str))  < std::numeric_limits<float>::min())
			std::cout << "impossible" << std::endl;
		// std::cout << "char: '" << static_cast<char>(stoi(str)) << "'" << std::endl;
		// std::cout << "int: " << static_cast<int>(stoi(str)) << std::endl;
		// std::cout << std::fixed << std::setprecision(1);
		// std::cout << "float: " << static_cast<float>(stof(str)) << "f" << std::endl;
		// std::cout << std::fixed << std::setprecision(1);
		// std::cout << "double: " << static_cast<double>(stod(str)) << std::endl;
	}
	if (type == DOUBLE)
	{
		if (isNegative)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(stoi(str)) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(stoi(str)) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(stof(str)) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << static_cast<double>(stod(str)) << std::endl;
	}
	if (type == CHAR)
	{
		char c = str[1];
		std::cout << "char: " << str << std::endl;
		std::cout << "int: " << static_cast<int>(c)<< std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	if (type == INT)
	{
		if (isNegative)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(stoi(str)) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(stoi(str)) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(stof(str)) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << static_cast<double>(stod(str)) << std::endl;
	}
	if (type == NAN || type == NANF)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	if (type == INF || type == INFF)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (isNegative)
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
	}
}
