#include "Fixed.hpp"


Fixed::Fixed()
{
    std::cout << "default constructor is called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
        std::cout << "copy constructor is called" << std::endl;
        this->fixed_point = fixed.fixed_point;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits(int fixed_point)
{
     std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = fixed_point;
}

Fixed::~Fixed()
{
    std::cout << "destructour is called " << std::endl;
}

 Fixed &Fixed::operator=(const Fixed &fixed)
 {
    if(this != &fixed)
        this->fixed_point = fixed.fixed_point;
    return *this;
 }