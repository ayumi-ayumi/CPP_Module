#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	_rawValue = nbr << _fractionalBits;
};

Fixed::Fixed(const float nbr)
{
	// std::cout << "Float constructor called" << std::endl;
	_rawValue = (int)roundf(nbr * (1 << _fractionalBits));
};

Fixed::Fixed(const Fixed& rhs)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
};

Fixed& Fixed::operator=(const Fixed& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_rawValue = rhs._rawValue;
	return (*this);
};

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	return (_rawValue);
};

void Fixed::setRawBits(int const raw)
{
	_rawValue = raw;
};

float Fixed::toFloat(void) const
{
	return((static_cast<float>(_rawValue) / (1 << _fractionalBits)));
};

int Fixed::toInt(void) const
{
	return ( _rawValue >> _fractionalBits);
};

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

bool Fixed::operator==(const Fixed& rhs)
{
	return _rawValue == rhs._rawValue;
};

bool Fixed::operator!=(const Fixed& rhs)
{
	return !(*this == rhs);
};

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}


Fixed& Fixed::operator++() // ++a
{
	++_rawValue;
	return (*this);
}

Fixed& Fixed::operator--() // --a
{
	--_rawValue;
	return (*this);
}

Fixed Fixed::operator++(int) // a++
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed Fixed::operator--(int) // a--
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

bool	Fixed::operator<(const Fixed& rhs)
{
	return _rawValue < rhs.getRawBits();
}

bool	Fixed::operator>(const Fixed& rhs)
{
	return _rawValue > rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed& rhs)
{
	return _rawValue <= rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed& rhs)
{
	return _rawValue >= rhs.getRawBits();
}

std::ostream& operator<<(std::ostream &out, const Fixed& rhs)
{
	out << rhs.toFloat();
	return (out);
};
