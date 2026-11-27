template <typename T>
Array<T>::Array(): _ptr(NULL), _num(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _ptr(new T[n]()), _num(n) {} // new int() means initialize as 0(default)

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other): _ptr(new T[other._num]()), _num(other._num)
{
	for (unsigned int i = 0; i < _num; i++)
		_ptr[i] = other._ptr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		T *newPtr = new T[rhs._num]();
		for (unsigned int i = 0; i < rhs._num; i++)
			newPtr[i] = rhs._ptr[i];

		delete[] _ptr;
		_ptr = newPtr;
		_num = rhs._num;
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
	if (_num == 0 || i >= _num)
		throw (OutOfBounds());
	else
		return _ptr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _ptr;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_num);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return ("Index is out of bounds");
}
