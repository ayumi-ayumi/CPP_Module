#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _requiredGrade(150), _executedGrade(150) {}

Form::Form(const std::string &formName, int requiredGrade, int executedGrade) : _name(formName), _isSigned(false), _requiredGrade(requiredGrade), _executedGrade(executedGrade)
{
	if (_requiredGrade < 1 || _executedGrade < 1)
		throw (GradeTooHighException());
	if (_requiredGrade > 150 || _executedGrade > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _requiredGrade(other._requiredGrade), _executedGrade(other._executedGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getRequiredGrade() const
{
	return (_requiredGrade);
}

int Form::getExecutedGrade() const
{
	return (_executedGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredGrade)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &out, const Form& other)
{
	out << other.getName() 
	<< ", form signed: " << (other.getIsSigned() ? "Yes" : "No")
	<< ", required grade is " << other.getRequiredGrade()
	<< ", executed grade is " << other.getExecutedGrade();
	return (out);
}
