#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") 
{
	std::cout << "WrongAnimal default constructor created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "No sound" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return (_type);
}

