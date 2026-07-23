#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) // in case of Point b(a)
{
	*this = other;
}

Point& Point::operator=(const Point& other)
{
	(void) other;
	return (*this);
}

Point::~Point() {}

float Point::getX() const
{
	return (_x.toFloat());
}

float Point::getY() const
{
	return (_y.toFloat());
}
