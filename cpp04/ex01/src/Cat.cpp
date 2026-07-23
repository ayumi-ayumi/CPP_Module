#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal(), _catBrain(new Brain())
{
	this->_type = "Cat";
	std::cout << "Cat default constructor created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _catBrain(new Brain(*other._catBrain))
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
	delete _catBrain;
}

void Cat::makeSound() const
{
	std::cout << "Nya nya" << std::endl;
}