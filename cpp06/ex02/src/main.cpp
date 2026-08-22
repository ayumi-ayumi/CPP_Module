#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(NULL));
	Base* const ayumi = generate();
	identify(ayumi);
	identify(*ayumi);
	delete ayumi;
}
