#include "Array.hpp"
#include <iostream>

int main()
{
	int num = 5;
	try
	{
		Array<int> d(num);
		// for (int i = 0; i < num; i++)
		// 	d[i] = (i + 1) / 3.0f;
		// for (int i = 0; i < num; i++)
		// 	std::cout << d[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}
