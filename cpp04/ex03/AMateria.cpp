#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {} 

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria(){}

std::string const& AMateria::getType() const //Returns the materia type
{
	return (_type);	
}
