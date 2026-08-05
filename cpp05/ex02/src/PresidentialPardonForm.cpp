#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5) , _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void) other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" <<std::endl;
}