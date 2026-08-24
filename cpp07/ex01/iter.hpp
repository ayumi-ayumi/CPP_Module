#ifndef _ITER_H_
#define _ITER_H_
#include <iostream>

template <typename T>
void multiDouble(T &num)
{
	num = num * 2;
}

template <typename T1, typename F>
void iter(T1 *arr, const int len, F func)
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
		std::cout << "arr[" << i << "] -> " << arr[i] << std::endl;
	}
}

#endif
