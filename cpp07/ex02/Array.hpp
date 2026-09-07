#ifndef _ARRAY_H_
#define _ARRAY_H_
#include "Array.tpp"

class Array
{
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	int size();
};

#endif
