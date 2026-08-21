
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
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (CHAR);
	else if (str == "nan" || str == "+inf" || str == "-inf")
		return (D_PSEUDO);
	else if (str == "nanf" || str == "+inff" || str == "-inff")
		return (F_PSEUDO);
	else if (str[str.length() - 1] == 'f' && isAllDigit(str))
		return (FLOAT);
	else if (str.find('.') != std::string::npos && isAllDigit(str))
		return (DOUBLE);
	else if (isInt(str))
		return (INT);
	else
		return (INVALID);
}

void countFloat(std::string str, int &n)
{
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < str.length())
	{
		if (isdigit(str[i]))
			i++;
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '0')
			{
				i++;
				n++;
			}
			if (str[i] == 'f')
				return ;
		}
	}
}

void ScalarConverter::convert(const std::string &str)
{
	int isNegative = 0;
	int type = detectType(str, isNegative);
	int n = 0;
	countFloat(str, n);
	if (type == INVALID)
	{
		std::cout << "Invalid input, it cannot be detected" << std::endl;
		return;
	}
	if (type == FLOAT)
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
		errno = 0;
		end = NULL;
		double value_double = strtod(str.c_str(), &end);
		if (errno == ERANGE)
			std::cout << "double: impossible" << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(n) << "double: " << value_double << std::endl;
		}
		errno = 0;
		end = NULL;
		long value_int = strtol(str.c_str(), &end, 10);
		if (value_int > std::numeric_limits<int>::max() || value_int < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << value_int << std::endl;
	}
	if (type == DOUBLE)
	{
		errno = 0;
		char *end;
		double value = strtod(str.c_str(), &end);
		if (errno == ERANGE)
		{
			std::cout << "double: impossible" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(n) << "double: " << value << std::endl;

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
		errno = 0;
		end = NULL;
		float value_float = strtof(str.c_str(), &end);
		if (errno == ERANGE)
			std::cout << "float: impossible" << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(n) << "float: " << value_float << "f" <<std::endl;
		}
		errno = 0;
		end = NULL;
		long value_int = strtol(str.c_str(), &end, 10);
		if (value_int > std::numeric_limits<int>::max() || value_int < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << value_int << std::endl;
	}
	// if (type == CHAR)
	// {
	// 	char c = str[1];
	// 	std::cout << "char: " << str << std::endl;
	// 	std::cout << "int: " << static_cast<int>(c)<< std::endl;
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << "double: " << static_cast<double>(c) << std::endl;
	// }
	// if (type == INT)
	// {
	// 	if (isNegative)
	// 		std::cout << "char: impossible" << std::endl;
	// 	else
	// 		std::cout << "char: '" << static_cast<char>(stoi(str)) << "'" << std::endl;
	// 	std::cout << "int: " << static_cast<int>(stoi(str)) << std::endl;
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << "float: " << static_cast<float>(stof(str)) << "f" << std::endl;
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << "double: " << static_cast<double>(stod(str)) << std::endl;
	// }
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
