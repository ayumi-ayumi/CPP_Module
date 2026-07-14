#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_rawValue = nbr * (1 << _fractionalBits);
};

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_rawValue = roundf(nbr * (1 << _fractionalBits));
};

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
};

Fixed &Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_rawValue = rhs._rawValue;
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	return (_rawValue);
};

void Fixed::setRawBits(int const raw)
{
	_rawValue = raw;
};

float Fixed::toFloat( void ) const
{
	return (_rawValue / (float)(1 << _fractionalBits));
};

int Fixed::toInt( void ) const
{
	return ( _rawValue / (1 << _fractionalBits));
};

std::ostream& operator<<(std::ostream &out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
};
