#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		// _name = other._name;
		_grade = other._grade;
	}
	return (*this);
	
}

Bureaucrat::~Bureaucrat() {}


const std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setName(std::string name)
{
	_name = name;
}

void Bureaucrat::setGrade(unsigned int grade)
{
	_grade = grade;
}

void Bureaucrat::increaseGrade()
{
	_grade --;
}

void Bureaucrat::decreaseGrade()
{
	_grade ++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (out);
}
