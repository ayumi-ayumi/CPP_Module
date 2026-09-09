#ifndef _ARRAY_H_
#define _ARRAY_H_

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		int size();
};

#include "Array.tpp"

#endif
