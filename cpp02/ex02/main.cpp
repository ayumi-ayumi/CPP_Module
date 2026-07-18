#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << "========== COMPARISON OPERATORS ==========\n";
	Fixed a(5);
	Fixed b(10);
	Fixed c(5);
	Fixed d(-3);
	Fixed e(-1);

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << "a > b  : " << (a > b) << std::endl;
	std::cout << "a < b  : " << (a < b) << std::endl;
	std::cout << "a >= c : " << (a >= c) << std::endl;
	std::cout << "a <= c : " << (a <= c) << std::endl;
	std::cout << "a == c : " << (a == c) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "d < e  : " << (d < e) << std::endl;
	std::cout << std::endl;


	std::cout << "========== ADDITION ==========\n";
	std::cout << "3 + 2 = " << Fixed(3) + Fixed(2) << std::endl;
	std::cout << "1.5 + 2.25 = " << Fixed(1.5f) + Fixed(2.25f) << std::endl;
	std::cout << "-5 + 3 = " << Fixed(-5) + Fixed(3) << std::endl;
	std::cout << std::endl;


	std::cout << "========== SUBTRACTION ==========\n";
	std::cout << "10 - 3 = " << Fixed(10) - Fixed(3) << std::endl;
	std::cout << "3.5 - 1.25 = " << Fixed(3.5f) - Fixed(1.25f) << std::endl;
	std::cout << "2 - 5 = " << Fixed(2) - Fixed(5) << std::endl;
	std::cout << std::endl;


	std::cout << "========== MULTIPLICATION ==========\n";
	std::cout << "3 * 4 = " << Fixed(3) * Fixed(4) << std::endl;
	std::cout << "1.5 * 2 = " << Fixed(1.5f) * Fixed(2) << std::endl;
	std::cout << "-2 * 3 = " << Fixed(-2) * Fixed(3) << std::endl;
	std::cout << "100 * 0 = " << Fixed(100) * Fixed(0) << std::endl;
	std::cout << std::endl;


	std::cout << "========== DIVISION ==========\n";
	std::cout << "10 / 2 = " << Fixed(10) / Fixed(2) << std::endl;
	std::cout << "5 / 2 = " << Fixed(5) / Fixed(2) << std::endl;
	std::cout << "-10 / 2 = " << Fixed(-10) / Fixed(2) << std::endl;
	std::cout << "123.45 / 1 = " << Fixed(123.45f) / Fixed(1) << std::endl;
	std::cout << "10 / 0 = " << Fixed(10) / Fixed(0) << std::endl;
	std::cout << std::endl;


	std::cout << "========== PRE-INCREMENT ==========\n";
	Fixed pre;
	std::cout << "initial : " << pre << std::endl;
	std::cout << "++pre   : " << ++pre << std::endl;
	std::cout << "after   : " << pre << std::endl;
	++pre;
	std::cout << "++pre   : " << pre << std::endl;
	std::cout << std::endl;


	std::cout << "========== POST-INCREMENT ==========\n";
	Fixed post;
	std::cout << "initial : " << post << std::endl;
	std::cout << "post++  : " << post++ << std::endl;
	std::cout << "after   : " << post << std::endl;
	std::cout << std::endl;


	std::cout << "========== PRE-DECREMENT ==========\n";
	Fixed preDec(1);
	std::cout << "initial : " << preDec << std::endl;
	std::cout << "--preDec: " << --preDec << std::endl;
	std::cout << "after   : " << preDec << std::endl;
	std::cout << std::endl;


	std::cout << "========== POST-DECREMENT ==========\n";
	Fixed postDec(1);
	std::cout << "initial : " << postDec << std::endl;
	std::cout << "postDec--: " << postDec-- << std::endl;
	std::cout << "after    : " << postDec << std::endl;
	std::cout << std::endl;


	std::cout << "========== MIN / MAX ==========\n";
	Fixed x(5);
	Fixed y(10);

	std::cout << "min(x,y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "min(y,x) = " << Fixed::min(y, x) << std::endl;
	std::cout << "max(x,y) = " << Fixed::max(x, y) << std::endl;
	std::cout << "max(y,x) = " << Fixed::max(y, x) << std::endl;

	Fixed const cx(4);
	Fixed const cy(9);

	std::cout << "const min = " << Fixed::min(cx, cy) << std::endl;
	std::cout << "const max = " << Fixed::max(cx, cy) << std::endl;
	std::cout << std::endl;


	std::cout << "========== CHAINED EXPRESSIONS ==========\n";
	Fixed f(2);
	Fixed g(3);
	Fixed h(4);

	std::cout << "2 + 3 * 4 = " << f + g * h << std::endl;

	Fixed chain;
	++++chain;
	std::cout << "++++chain = " << chain << std::endl;

	Fixed result = f + g;
	std::cout << "result = " << result << std::endl;
	std::cout << std::endl;


	std::cout << "========== SUBJECT TEST ==========\n";
	Fixed subjectA;
	Fixed const subjectB(Fixed(5.05f) * Fixed(2));

	std::cout << subjectA << std::endl;
	std::cout << ++subjectA << std::endl;
	std::cout << subjectA << std::endl;
	std::cout << subjectA++ << std::endl;
	std::cout << subjectA << std::endl;
	std::cout << subjectB << std::endl;
	std::cout << Fixed::max(subjectA, subjectB) << std::endl;

	return (0);
}


/*
========== COMPARISON OPERATORS ==========
a = 5, b = 10, c = 5
a > b  : 0
a < b  : 1
a >= c : 1
a <= c : 1
a == c : 1
a != b : 1
d < e  : 1

========== ADDITION ==========
3 + 2 = 5
1.5 + 2.25 = 3.75
-5 + 3 = -2

========== SUBTRACTION ==========
10 - 3 = 7
3.5 - 1.25 = 2.25
2 - 5 = -3

========== MULTIPLICATION ==========
3 * 4 = 12
1.5 * 2 = 3
-2 * 3 = -6
100 * 0 = 0

========== DIVISION ==========
10 / 2 = 5
5 / 2 = 2.5
-10 / 2 = -5
123.45 / 1 = 123.449

========== PRE-INCREMENT ==========
initial : 0
++pre   : 0.00390625
after   : 0.00390625
++pre   : 0.0078125

========== POST-INCREMENT ==========
initial : 0
post++  : 0
after   : 0.00390625

========== PRE-DECREMENT ==========
initial : 1
--preDec: 0.996094
after   : 0.996094

========== POST-DECREMENT ==========
initial : 1
postDec--: 1
after    : 0.996094

========== MIN / MAX ==========
min(x,y) = 5
min(y,x) = 5
max(x,y) = 10
max(y,x) = 10
const min = 4
const max = 9

========== CHAINED EXPRESSIONS ==========
2 + 3 * 4 = 14
++++chain = 0.0078125
result = 5

========== SUBJECT TEST ==========
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/
