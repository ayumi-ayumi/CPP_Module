#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <string>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		// Array& operator=(const Array& other);
		T& operator[](int i);
		~Array();

		class OutOfBounds : public std::exception
		{
			const char*		what() const throw();
		};


		int size();
		T* ptr;
		int num;
};

#include "Array.tpp"

#endif
