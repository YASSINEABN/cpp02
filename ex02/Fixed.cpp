#include "Fixed.hpp"


Fixed::Fixed()
{
   
    this->fixed_point = 0;
}

Fixed::Fixed(const int num)
{
    this->fixed_point =  roundf((num * pow(2,fractional_bits)));
}

Fixed::Fixed(const float num)
{
        this->fixed_point = roundf((num * pow(2,fractional_bits)));
}


Fixed::Fixed(const Fixed &fixed)
{
        *this = fixed;
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
}

 Fixed &Fixed::operator=(const Fixed &fixed)
 {
        this->fixed_point = fixed.getRawBits();
        return *this;
 }

float Fixed::toFloat(void) const
{
    return (float)((this->fixed_point / pow(2,fractional_bits)));
}

int Fixed::toInt(void) const
{
    return (int)((this->fixed_point / pow(2,fractional_bits)));
}

   std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
   {
        return (os << fixed.toFloat());
   }

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
    return *this;
}


Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() +1 );
    return temp;
}

Fixed &Fixed::operator--()
{
     this->fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{  Fixed temp = *this;
    this->fixed_point--;

    return temp;
}

Fixed Fixed::operator*(const Fixed& copy) const
{
    Fixed c;
    c.fixed_point = this->toFloat() * copy.getRawBits();
    return c;
}

Fixed Fixed::operator+(const Fixed& copy) const
{
   Fixed c;
    c.setRawBits(copy.getRawBits() + this->toFloat());
    return c;
}


Fixed Fixed::operator-(const Fixed& copy) const
{
   Fixed c;
    c.setRawBits(copy.getRawBits() - this->toFloat());
    return c;
}

Fixed Fixed::operator/(const Fixed& copy) const
{
   Fixed c;
    c.setRawBits(copy.getRawBits() / this->toFloat());
    return c;
}

bool Fixed::operator>(const Fixed &copy) const
{
    return (this->getRawBits() > copy.getRawBits());
}

bool Fixed::operator<(const Fixed &copy) const
{
    return this->getRawBits() < copy.getRawBits();
}

bool Fixed::operator==(const Fixed &copy) const
{
        return (this->getRawBits() == copy.getRawBits());
}

bool Fixed::operator<=(const Fixed &copy) const
{
    return (this->getRawBits() <= copy.getRawBits());
}

bool Fixed::operator>=(const Fixed &copy) const
{
    return (this->getRawBits() >= copy.getRawBits());
}

bool Fixed::operator!=(const Fixed &copy) const
{
    return (this->getRawBits() != copy.getRawBits());
}

 const Fixed  &Fixed::max(  const Fixed &obj1 , const Fixed &obj2) 
{
    if(obj1.getRawBits() > obj2.getRawBits())
        return obj1;
    else 
        return obj2;
}

 const Fixed  &Fixed::min(  const Fixed &obj1 , const Fixed &obj2) 
{
    if(obj1.getRawBits() < obj2.getRawBits())
        return obj1;
    else 
        return obj2;
}