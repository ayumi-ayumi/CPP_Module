#ifndef _POINT_H_
#define _POINT_H_
#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		float		getX() const;
		float		getY() const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
