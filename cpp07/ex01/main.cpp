#include "iter.hpp"


int main()
{
	const int array[5] = {0, 1, 2, 3, 4};
	const int len = 5;
	::iter(array, len, multiDouble<int>);
}
