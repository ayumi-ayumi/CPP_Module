#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cstdlib>
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
	INVALID
};

bool isInt(const std::string &str)
{
	int i = 0;
	bool sign = false;
	if (str[0] == '-' || str[0] == '+')
	{
		sign = true;
		i++;
	}
	while (str[i])
	{
		if (isdigit(str[i]))
			i++;
		else
			return (false);
	}
	if (sign && i == 1)
		return (false);
	return (true);
}

bool isAllDigit(std::string str)
{
	size_t i = 0;
	int point_flag = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == 'f')
			return (false);
		i++;
	}
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			point_flag++;
			i++;
			if (point_flag > 1)
				return (false);
		}
		if (i == str.length() - 1 && str[i] == 'f')
				return (true);
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int detectType(const std::string &str)
{
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

int countFractionalBits(std::string str)
{
	int n = 0;
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
	return (n);
}

void printChar(std::string str)
{
	char *end;
	long value = strtol(str.c_str(), &end, 10);
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "char: impossible" << std::endl;
	else
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

void printFloat(std::string str, int fractionalBits)
{
	if (fractionalBits == 0)
		fractionalBits = 1;
	errno = 0;
	char *end;
	float value = strtof(str.c_str(), &end);
	if (errno == ERANGE)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(fractionalBits) << "float: " << value << "f" << std::endl;
}

void printDouble(std::string str, int fractionalBits)
{
	errno = 0;
	char *end;
	double value_double = strtod(str.c_str(), &end);
	if (errno == ERANGE)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(fractionalBits) << "double: " << value_double << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	if (str == "")
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	int type = detectType(str);
	std::cout << type << std::endl;
	int fractionalBits = countFractionalBits(str);
	if (type == INVALID)
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	if (type == FLOAT || type == DOUBLE || type == INT)
	{
		printChar(str);
		printInt(str);
		printFloat(str, fractionalBits);
		printDouble(str, fractionalBits);
	}
	if (type == CHAR)
	{
		char c = static_cast<char>(str[0]);
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c)<< std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
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
