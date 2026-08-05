#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _requiredGrade(150), _executedGrade(150) {}

AForm::AForm(const std::string &formName, int requiredGrade, int executedGrade) : _name(formName), _isSigned(false), _requiredGrade(requiredGrade), _executedGrade(executedGrade)
{
	if (_requiredGrade < 1 || _executedGrade < 1)
		throw (GradeTooHighException());
	if (_requiredGrade > 150 || _executedGrade > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _requiredGrade(other._requiredGrade), _executedGrade(other._executedGrade) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getRequiredGrade() const
{
	return (_requiredGrade);
}

int AForm::getExecutedGrade() const
{
	return (_executedGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredGrade)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream &out, const AForm& other)
{
	out << other.getName() 
	<< ", form signed: " << (other.getIsSigned() ? "Yes" : "No")
	<< ", required grade is " << other.getRequiredGrade()
	<< ", executed grade is " << other.getExecutedGrade();
	return (out);
}
