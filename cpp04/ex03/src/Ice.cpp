#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) :  AMateria("ice") {} 

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

Ice::~Ice(){}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}