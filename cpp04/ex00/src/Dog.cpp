#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->_type = "dog";
	std::cout << "Dog default constructor created" << std::endl;

}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_type = "dog";
	std::cout << "Dog copy constructor created" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog() 
{
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wan wan" << std::endl;
}
