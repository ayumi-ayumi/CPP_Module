#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		return (*this);
}

Intern::~Intern();

AForm* Intern::makeForm(std::string name, std::string target)
{
	
}
