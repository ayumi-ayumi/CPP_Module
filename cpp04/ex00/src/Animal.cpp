#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") 
{
	std::cout << "Animal default constructor created" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor created" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal() 
{
	std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "No sound" << std::endl;
}

const std::string Animal::getType() const
{
	return (_type);
}

