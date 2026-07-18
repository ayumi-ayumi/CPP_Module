#ifndef _FIXED_H_
#define _FIXED_H_
#include <ostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		bool					operator>(const Fixed& rhs);
		bool					operator<(const Fixed& rhs);
		bool					operator>=(const Fixed& rhs);
		bool					operator<=(const Fixed& rhs);

		bool					operator==(const Fixed& rhs);
		bool					operator!=(const Fixed& rhs);

		Fixed					operator+(const Fixed& rhs) const;
		Fixed					operator-(const Fixed& rhs) const;
		Fixed					operator*(const Fixed& rhs) const;
		Fixed					operator/(const Fixed& rhs) const;

		Fixed& 					operator++(); // ++a
		Fixed&					operator--(); // --a
		Fixed					operator++(int); // a++
		Fixed					operator--(int); // a--

		int						getRawBits(void) const;
		void					setRawBits(int const raw);
		float					toFloat(void) const;
		int						toInt(void) const;

		static Fixed&			min(Fixed& lhs, Fixed& rhs);
		static Fixed&			max(Fixed& lhs, Fixed& rhs);
		static const Fixed&		min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed&		max(const Fixed& lhs, const Fixed& rhs);
	private:
		int						_rawValue;
		static const int		_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed& rhs);

#endif
