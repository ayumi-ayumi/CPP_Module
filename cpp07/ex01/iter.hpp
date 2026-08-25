#ifndef _ITER_H_
#define _ITER_H_
#include <iostream>

template <typename T>
void multiDouble(T &num)
{
	num = num * 2;
	std::cout << num << std::endl;
}

template <typename T>
void printNum(const T &num)
{
	std::cout << num << std::endl;
}

template <typename T>
void iter(T *arr, const size_t len, void(*func)(T&))
{
	if (!arr || len == 0 || !func)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "arr[" << i << "] -> ";
		func(arr[i]);
	}
}

template <typename T>
void iter(T *arr, const size_t len, void(*func)(const T&))
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
