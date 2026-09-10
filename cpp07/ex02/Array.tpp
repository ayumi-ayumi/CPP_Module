template <typename T>
Array<T>::Array() {};

template <typename T>
Array<T>::Array(unsigned int n): num(n)
{
	ptr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	(void)other;
}

template <typename T>
T& Array<T>::operator[](int i)
{
	if (i > num || i < num)
		throw (OutOfBounds());
	else
		return ptr[i];
}


// template <typename T>
// Array& Array<T>::operator=(const Array& other){}

template <typename T>
Array<T>::~Array()
{
	delete[] ptr;
}

template <typename T>
int Array<T>::size()
{
	int i = 0;
	while (ptr[i])
		i++;
	return (i);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return ("Index is out of bounds");
}
