#ifndef _FIXED_H_
#define _FIXED_H_

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;
};

#endif


/*
Test code

class Fixed {
	public:
		Fixed(std::string name);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					fixed_point;
		static const int	bits = 8;
		std::string			_name;
};

*/
