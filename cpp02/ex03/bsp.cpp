#include "Fixed.hpp"
#include "Point.hpp"

Point sub_vec(const Point& a, const Point& b)
{
	return (Point(a.getX() - b.getX(), a.getY() - b.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Vector
	Point vecAB = sub_vec(b, a);
	Point vecBP = sub_vec(point, b);

	Point vecBC = sub_vec(c, b);
	Point vecCP = sub_vec(point, c);

	Point vecCA = sub_vec(a, c);
	Point vecAP = sub_vec(point, a);

	// Cross product
	float cross1 = (vecAB.getX() * vecBP.getY()) - (vecAB.getY() * vecBP.getX());
	float cross2 = (vecBC.getX() * vecCP.getY()) - (vecBC.getY() * vecCP.getX());
	float cross3 = (vecCA.getX() * vecAP.getY()) - (vecCA.getY() * vecAP.getX());

	if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return (true);
	return (false);
};
