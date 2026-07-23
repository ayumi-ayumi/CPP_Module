#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->_type = "Cat";
	std::cout << "Cat copy constructor created" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat() 
{
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Nya nya" << std::endl;
}
