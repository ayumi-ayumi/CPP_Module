#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	this->_type = "WrongCat";
	std::cout << "WrongCat copy constructor created" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Nya nya" << std::endl;
}
