#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
	int idx = rand() % 3;
	if (idx == 0)
		return new A();
	else if (idx == 1)
		return new B();
	else
		return new C();
}
