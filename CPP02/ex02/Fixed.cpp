#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->_rawBits = 0;
}
Fixed::Fixed(int const n)
{
    this->_rawBits = n * (1 << this->_fractionalBits);
}
Fixed::Fixed(float const n)
{
    this->_rawBits = roundf(n * (1 << this->_fractionalBits));
}
Fixed::Fixed(const Fixed &other)
{
    _rawBits = other.getRawBits();
}
Fixed::~Fixed()
{
}
Fixed &Fixed::operator=(const Fixed &other)
{
    
}