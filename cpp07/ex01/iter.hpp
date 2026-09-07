#ifndef _ITER_H_
#define _ITER_H_
#include <iostream>

template <typename T, typename F>
void iter(T *arr, const size_t len, F func)
{
	if (!arr || len == 0 || !func)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "arr[" << i << "] -> ";
		func(arr[i]);
	}
}

#endif
