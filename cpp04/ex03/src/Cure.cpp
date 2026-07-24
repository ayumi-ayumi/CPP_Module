#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") 
{
	std::cout << "Cure default constructor created" << std::endl;
}

Cure::Cure(const Cure& other) :  AMateria("cure") 
{
	std::cout << "Cure copy constructor created" << std::endl;
} 

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

Cure::~Cure(){}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
