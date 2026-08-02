#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _requiredGrade(150), _executedGrade(150) {}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _requiredGrade(other._requiredGrade), _executedGrade(other._executedGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {}

std::string Form::getName()
{
	return (_name);
}

bool Form::getIsSigned()
{
	return (_isSigned);
}

int Form::getRequiredGrade()
{
	return (_requiredGrade);
}

int Form::getExecutedGrade()
{
	return (_executedGrade);
}

// void Form::beSigned(const Bureaucrat& input)
// {
// 	if (input.getGrade() <= _requiredGrade)
// 		_isSigned = true;
// 	else
// 		throw (GradeTooLowException());
// }

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}