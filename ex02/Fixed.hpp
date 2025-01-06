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
        Fixed& operator++();
        Fixed operator++(int);
         Fixed operator--(int);
        Fixed& operator--();
    bool operator>( const Fixed &copy) const;
    Fixed operator+( const Fixed &copy) const;
    Fixed operator-( const Fixed &copy) const;
Fixed operator*(const Fixed& copy) const;
    Fixed operator/( const Fixed &copy) const;
    bool operator<(const Fixed &copy)const ;
    bool operator>=( const Fixed &copy) const;
    bool  operator<=( const Fixed &copy) const;
    bool operator==(const Fixed &copy) const;
    bool operator!=(const Fixed &copy) const;
static const Fixed &max(  const Fixed &obj1 , const Fixed &obj2) ;
static const Fixed &min(  const Fixed &obj1 , const Fixed &obj2) ;



    };

    std::ostream& operator<<(std::ostream &os,const Fixed &fixed);
    

#endif