#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45) , _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void) other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
	std::cout << "Gggggggzzzzzzzzjjjjj........" <<std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
