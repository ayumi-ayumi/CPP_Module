#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawValue(0)
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
		_rawValue = rhs.getRawBits(); // [OK]_rawValue = rhs._rawValue
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
};

void Fixed::setRawBits(int const raw)
{
	_rawValue = raw;
};

/*
Test code

Fixed::Fixed(std::string name) : _rawValue(0)
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
		_rawValue = rhs.getRawBits();
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
	return (_rawValue);
}

void Fixed::setRawBits(int const raw)
{
	_rawValue = raw;
}
*/
