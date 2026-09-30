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
		Array& operator=(const Array& rhs);
		~Array();

		T& operator[](unsigned int i);
		unsigned int size() const;
		class OutOfBounds : public std::exception { const char* what() const throw();};

	private:
		T* ptr;
		unsigned int num;
};

#include "Array.tpp"

#endif
