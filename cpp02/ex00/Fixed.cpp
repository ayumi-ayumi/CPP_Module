#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixed_point_nbr_value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
};

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_fixed_point_nbr_value = rhs.getRawBits();
	}
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_nbr_value);
};

void Fixed::setRawBits(int const raw)
{
	_fixed_point_nbr_value = raw;
};

/*
Test code

Fixed::Fixed(std::string name) : _fixed_point_nbr_value(0)
{
	m_name = name;
	std::cout << m_name <<": Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << m_name << ": Copy constructor called" << std::endl;
	*this = rhs;
};

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << m_name << ": Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_fixed_point_nbr_value = rhs.getRawBits();
	}
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	std::cout <<m_name << ": getRawBits member function called" << std::endl;
	return (_fixed_point_nbr_value);
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point_nbr_value = raw;
}
*/
