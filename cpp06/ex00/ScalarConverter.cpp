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

bool isInt(const string &str)
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
	if (sign && i == 1) // "-" or "+"
		return (false);
	return (true);
}

bool isAllDigit(string str)
{
	size_t i = 0;
	int decimal_point_flag = 0;
	if (str[0] == '.')
		return (false);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '.' || str[1] == 'f') // Check if it is not "-f" or "+f"
			return (false);
		i++;
	}
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			decimal_point_flag++;
			i++;
			if (decimal_point_flag > 1) // Check if it is not "4..5f"
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

int detectType(const string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return (D_PSEUDO);
	else if (str == "nanf" || str == "+inff" || str == "-inff")
		return (F_PSEUDO);
	else if (str[str.length() - 1] == 'f' && isAllDigit(str))
		return (FLOAT);
	else if (str.find('.') != string::npos && isAllDigit(str))
		return (DOUBLE);
	else if (isInt(str))
		return (INT);
	else if (str.length() == 1 || (str.length() == 3 && str[0] == '\'' && str[2] == '\''))
		return (CHAR);
	else
		return (INVALID);
}

int countFractionalDigits(string str)
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

void printChar(string str)
{
	errno = 0;
	char *end;
	long value = strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (static_cast<int>(value) >= 0 && static_cast<int>(value) <= 127)
		{
			if (isprint(static_cast<int>(value)))
				std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
}

void printInt(string str)
{
	errno = 0;
	char *end;
	long value = strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << value << std::endl;
}

void printFloat(string str, int fractionalDigits)
{
	if (fractionalDigits == 0)
		fractionalDigits = 1;
	errno = 0;
	char *end;
	float value = strtof(str.c_str(), &end);
	if (errno == ERANGE)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(fractionalDigits) << "float: " << value << "f" << std::endl;
}

void printDouble(string str, int fractionalDigits, int type)
{
	errno = 0;
	char *end;
	double value = strtod(str.c_str(), &end);
	if (errno == ERANGE)
		std::cout << "double: impossible" << std::endl;
	else
	{
		if (type == INT)
			std::cout << std::fixed << std::setprecision(fractionalDigits) << "double: " << value << ".0" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(fractionalDigits) << "double: " << value << std::endl;
	}
}

void ScalarConverter::convert(const string &str)
{
	int type = detectType(str);
	int fractionalDigits = countFractionalDigits(str);

	if (str == "" || type == INVALID)
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}

	if (type == FLOAT || type == DOUBLE || type == INT)
	{
		printChar(str);
		printInt(str);
		printFloat(str, fractionalDigits);
		printDouble(str, fractionalDigits, type);
	}

	if (type == CHAR)
	{
		char c;
		if (str.length() == 3)
			c = static_cast<char>(str[1]);
		else
			c = static_cast<char>(str[0]);
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c)<< std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}

	if (type == F_PSEUDO)
	{
		string sub_str = str.substr(0, str.length() - 1);
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
