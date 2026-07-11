#ifndef _FIXED_H_
#define _FIXED_H_

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& rhs);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int                 fixed_point;
};

static const int    bits = 8;

#endif