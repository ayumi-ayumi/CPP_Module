#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point tests[] =
	{
		Point(2, 2),     // inside
		Point(5, 2),     // inside
		Point(1, 8),     // inside
		Point(8, 8),     // outside
		Point(-1, 2),    // outside
		Point(2, -1),    // outside
		Point(0, 0),     // vertex
		Point(10, 0),    // vertex
		Point(0, 10),    // vertex
		Point(5, 0),     // edge AB
		Point(0, 5),     // edge AC
		Point(5, 5),     // edge BC
		Point(10, 10),   // outside
		Point(3, 6),     // inside
		Point(6, 3),     // inside
	};

	const char *expected[] =
	{
		"true",
		"true",
		"true",
		"false",
		"false",
		"false",
		"false",
		"false",
		"false",
		"false",
		"false",
		"false",
		"false",
		"true",
		"true"
	};

	for (int i = 0; i < 15; i++)
	{
		bool result = bsp(a, b, c, tests[i]);

		std::cout
			<< "Test " << i + 1
			<< " : expected = " << expected[i]
			<< " | got = " << (result ? "true" : "false")
			<< std::endl;
	}

	return (0);
};
