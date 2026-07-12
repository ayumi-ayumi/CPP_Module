#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*
[Fixed a;]Default constructor called
[Fixed b(a);]Copy constructor called
[Fixed b(a);]Copy assignment operator called // <-- This line may be missing depending on your implementation
[operator=]getRawBits member function called
[Fixed c]Default constructor called
[c=b]Copy assignment operator called
[c=b]getRawBits member function called
[std::cout << a.getRawBits() << std::endl;]getRawBits member function called
0
[std::cout << b.getRawBits() << std::endl;]getRawBits member function called
0
[std::cout << c.getRawBits() << std::endl;]getRawBits member function called
0
Destructor called
Destructor called
Destructor called
*/

/*
Who is calling? Empty is by "b".

a: Default constructor called
: Copy constructor called
: Copy assignment operator called
a: getRawBits member function called
c: Default constructor called
c: Copy assignment operator called
: getRawBits member function called
a: getRawBits member function called
0
: getRawBits member function called
0
c: getRawBits member function called
0
Destructor called
Destructor called
Destructor called
*/
