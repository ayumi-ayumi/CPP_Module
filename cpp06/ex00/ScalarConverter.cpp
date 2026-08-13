#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

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

void ScalarConverter::convert(std::string str)
{
	// std::cout << "char: " << static_cast<char>(str) << std::endl; 
	std::cout << "int: " << static_cast<int>(stoi(str)) << std::endl;
	std::cout << "float: " << static_cast<float>(stof(str)) << std::endl;
	std::cout << "double: " << static_cast<double>(stod(str)) << std::endl;
}