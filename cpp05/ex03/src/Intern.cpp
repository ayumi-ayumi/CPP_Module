#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) 
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

int findIdx(std::string forms[], std::string name)
{
	int idx = 0;
	while (idx < 3)
	{
		if (forms[idx] == name)
			return idx;
		idx++;
	}
	return (idx);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int nameIdx = findIdx(forms, name);

	switch (nameIdx)
	{
	case 0:
		std::cout << "Intern creates " << target << std::endl;
		return (new ShrubberyCreationForm(target));
		break;
	case 1:
		std::cout << "Intern creates " << target << std::endl;
		return (new RobotomyRequestForm(target));
		break;
	case 2:
		std::cout << "Intern creates " << target << std::endl;
		return (new PresidentialPardonForm(target));
		break;
	default:
		std::cout << "There is no form named " << target << std::endl;
		return (NULL);
		break;
	}
}
