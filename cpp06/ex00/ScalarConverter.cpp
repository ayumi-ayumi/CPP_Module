#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>

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

void checkInput(const std::string &str, std::string &type)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		type = "char";
	if (str == "nan")
		type = "nan";
	if (str[str.length() - 1] == 'f')
		type = "float";
	if (str[str.length() - 2] == '.')
		type = "double";

}

void ScalarConverter::convert(const std::string &str)
{
	std::string type;
	checkInput(str, type);
	std::cout << "type: " << type << std::endl;
	std::cout << "type outside checkInput: " << &type << std::endl;

	// std::cout << "char: " << static_cast<char>(str) << std::endl;
	// std::cout << "int: " << static_cast<int>(stoi(str)) << std::endl;
	// std::cout << "float: " << static_cast<float>(stof(str)) << std::endl;
	// std::cout << "double: " << static_cast<double>(stod(str)) << std::endl;
}
