#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixed_point_nbr_value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int nbr)
{
	_fixed_point_nbr_value = nbr * (1 << _fractionalBits);
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float nbr)
{
	_fixed_point_nbr_value = roundf(nbr * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
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
	{
		_fixed_point_nbr_value = rhs._fixed_point_nbr_value;
	}
	return (*this);
};

std::ostream& operator<<(std::ostream &out, const Fixed& rhs)
{
	float rtn = rhs.toFloat();
	out << rtn;
	return (out);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	return (_fixed_point_nbr_value);
};

void Fixed::setRawBits(int const raw)
{
	_fixed_point_nbr_value = raw;
};

float Fixed::toFloat( void ) const
{
	float	rtn;
	rtn = _fixed_point_nbr_value / 256.0f;
	return (rtn);
};

int Fixed::toInt( void ) const
{
	int rtn;
	rtn = _fixed_point_nbr_value / 256;
	return (rtn);
};
