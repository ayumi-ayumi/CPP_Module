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
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
	private:
		int					_fixed_point_nbr_value;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed& rhs);

#endif
