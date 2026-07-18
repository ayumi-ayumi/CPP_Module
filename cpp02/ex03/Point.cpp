#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const float x, const float y) : _x(x), _y(y) {};

Point::Point(const Point& rhs) : _x(rhs.getX()), _y(rhs.getY()) // in case of Point b(a)
{
	*this = rhs;
};

Point& Point::operator=(const Point& rhs)
{
	(void) rhs;
	return (*this);
};

Point::~Point() {};

float Point::getX() const
{
	return (_x.toFloat());
};

float Point::getY() const
{
	return (_y.toFloat());
};
