#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

    class Fixed
    {
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        float toFloat(void) const;
        int toInt(void) const;
        float getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(const Fixed &fixed);
    };

   std::ostream& operator<<(std::ostream &os,const Fixed &fixed);



#endif