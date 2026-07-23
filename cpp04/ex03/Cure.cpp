#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) :  AMateria("cure") {} 

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

Cure::~Cure(){}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << name << "’s wounds *" << std::endl;
}
