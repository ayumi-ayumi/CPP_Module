#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixed_point_nbr(0)
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
		fixed_point_nbr = rhs.getRawBits();
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
	return (fixed_point_nbr);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_nbr = raw;
}


/*
Test code

Fixed::Fixed(std::string name) : fixed_point_nbr(0)
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
		fixed_point_nbr = rhs.getRawBits();
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
	return (fixed_point_nbr);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_nbr = raw;
}
*/
