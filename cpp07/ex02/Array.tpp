template <typename T>
Array<T>::Array(): ptr(NULL), num(0) {};

template <typename T>
Array<T>::Array(unsigned int n): ptr(new T[n]()), num(n) {} // new int() means initialize as 0(default)

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other): ptr(new T[other.num]()), num(other.num)
{
	for (unsigned int i = 0; i < num; i++)
		ptr[i] = other.ptr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		delete[] ptr;
		num = rhs.num;
		ptr = new T[num]();
		for (unsigned int i = 0; i < num; i++)
			ptr[i] = rhs.ptr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= num)
		throw (OutOfBounds());
	else
		return ptr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] ptr;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (num);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return ("Index is out of bounds");
}
