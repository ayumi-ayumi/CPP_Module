#ifndef _ITER_H_
#define _ITER_H_
#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t len, F function) //F should be void (*f)(&T)?
{
	if (!array || len == 0)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "array[" << i << "] -> ";
		function(array[i]);
	}
}
// need const ver
template <typename T, typename F>
void iter(const T *array, const size_t len, F function)
{
	if (!array || len == 0)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "array[" << i << "] -> ";
		function(array[i]);
	}
}
#endif
