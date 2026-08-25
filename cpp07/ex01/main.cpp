#include "iter.hpp"

int main()
{
	int array[5] = {0, 1, 2, 3, 4};
	size_t len = sizeof(array) / sizeof(array[0]);
	std::cout << "const" << std::endl;
	::iter(array, len, printNum<int>);
	std::cout << "non-const" << std::endl;
	::iter(array, len, multiDouble<int>);
}
