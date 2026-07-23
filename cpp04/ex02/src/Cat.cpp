#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"), _catBrain(new Brain())
{
	std::cout << "Cat default constructor created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _catBrain(new Brain(*other._catBrain))
{
	std::cout << "Cat copy constructor created" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_catBrain;
		this->_catBrain = new Brain(*other._catBrain);
	}
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