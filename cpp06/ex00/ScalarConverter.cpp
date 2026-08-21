
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <cerrno>

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
	D_PSEUDO,
	F_PSEUDO,
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

int isAllDigit(std::string str)
{
	size_t i = 0;
	int dot_flag = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			dot_flag++;
			i++;
			if (dot_flag > 1)
				return (0);
		}
		if (i == str.length() - 1)
		{
			if (str[i] == 'f')
				return (1);
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int detectType(const std::string &str, int &isNegative)
{
	if (str[0] == '-')
		isNegative = 1;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return (D_PSEUDO);
	else if (str == "nanf" || str == "+inff" || str == "-inff")
		return (F_PSEUDO);
	else if (str[str.length() - 1] == 'f' && isAllDigit(str))
		return (FLOAT);
	else if (str.find('.') != std::string::npos && isAllDigit(str))
		return (DOUBLE);
	else if (isInt(str))
		return (INT);
	else if (str.length() == 1)
		return (CHAR);
	else
		return (INVALID);
}

void countFloat(std::string str, int &n)
{
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (isdigit(str[i]) && i < str.length())
	{
		n++;
		i++;
	}
}

template <typename T>
void printChar(T value)
{
	if (static_cast<int>(value) >= 0 && static_cast<int>(value) <= 127)
	{
		if (static_cast<int>(value) > 31 && static_cast<int>(value) < 127)
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void printFloat(std::string str, int n)
{
	errno = 0;
	char *end;
	float value = strtof(str.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(n) << "float: " << value << "f" << std::endl;
		printChar(value);
	}
}

void printInt(std::string str)
{
	char *end;
	long value_int = strtol(str.c_str(), &end, 10);
	if (value_int > std::numeric_limits<int>::max() || value_int < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << value_int << std::endl;
}

void printDouble(std::string str, int n)
{
	errno = 0;
	char *end;
	double value_double = strtod(str.c_str(), &end);
	if (errno == ERANGE)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(n) << "double: " << value_double << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	int isNegative = 0;
	int type = detectType(str, isNegative);
	if (type == INVALID)
	{
		std::cout << "Invalid input, it cannot be detected" << std::endl;
		return;
	}
	if (type == FLOAT)
	{
		int n = 0;
		countFloat(str, n);
		printFloat(str, n);
		printDouble(str, n);
		printInt(str);
	}
	if (type == DOUBLE)
	{
		int n = 0;
		countFloat(str, n);
		printDouble(str,n);
		printFloat(str, n);
		printInt(str);
	}
	if (type == CHAR)
	{
		char c = static_cast<char>(str[0]);
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c)<< std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	if (type == INT)
	{
		printInt(str);
		printFloat(str, 1);
		printDouble(str, 1);
	}
	if (type == F_PSEUDO)
	{
		std::string sub_str = str.substr(0, str.length() - 1);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << sub_str<< "f" << std::endl;
		std::cout << "double: " << sub_str << std::endl;
	}
	if (type == D_PSEUDO)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}
