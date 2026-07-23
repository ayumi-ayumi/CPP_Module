#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal() : _type("AAnimal") 
{
	std::cout << "AAnimal default constructor created" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) 
{
	std::cout << "AAnimal default constructor created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor created" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal() 
{
	std::cout << "AAnimal destroyed" << std::endl;
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "No sound" << std::endl;
// }

const std::string AAnimal::getType() const
{
	return (_type);
}

