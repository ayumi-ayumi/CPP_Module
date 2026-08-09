#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &formName, int requiredGrade, int executedGrade) : _name(formName), _isSigned(false), _gradeToSign(requiredGrade), _gradeToExecute(executedGrade)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

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

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw (GradeTooLowException());
	else if (!_isSigned)
		throw (FormNotSignedException());
	else
		action();
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

std::ostream& operator<<(std::ostream &out, const AForm& input)
{
	out << input.getName()
	<< ", form signed: " << (input.getIsSigned() ? "Yes" : "No")
	<< ", required grade is " << input.getGradeToSign()
	<< ", executed grade is " << input.getGradeToExecute();
	return (out);
}
