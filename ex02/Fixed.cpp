#include "Fixed.hpp"


Fixed::Fixed()
{
    std::cout << "default constructor is called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const int num)
{
        std::cout << "int constructor is called" << std::endl;
    this->fixed_point =  roundf((num * pow(2,fractional_bits)));
}

Fixed::Fixed(const float num)
{
        std::cout << "float constructor is called" << std::endl;
        this->fixed_point =roundf((num * pow(2,fractional_bits)));
}


Fixed::Fixed(const Fixed &fixed)
{
        std::cout << "copy constructor is called" << std::endl;
        this->fixed_point = fixed.fixed_point;
}

float Fixed::getRawBits() const
{
    return this->fixed_point;
}

void Fixed::setRawBits(int fixed_point)
{
    this->fixed_point = fixed_point;
}

Fixed::~Fixed()
{
    std::cout << "destructour is called " << std::endl;
}

 Fixed &Fixed::operator=(const Fixed &fixed)
 {
            std::cout << "copy assignement operator is called" << std::endl;

    if(this != &fixed)
        this->fixed_point = fixed.fixed_point;
    return *this;
 }

float Fixed::toFloat(void) const
{
    return (float)(((this->fixed_point / pow(2,fractional_bits))));
}

int Fixed::toInt(void) const
{
    return (int)(((this->fixed_point / pow(2,fractional_bits))));
}

   std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
   {
        os << fixed.toFloat() << std::endl;
        return os;
   }
