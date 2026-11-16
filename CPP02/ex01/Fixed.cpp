#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}
Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawbits = n << this->_fractionalBits;
}
Fixed::Fixed(float const n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawbits = roundf(n * (1 << this->_fractionalBits));
}
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _rawbits = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_rawbits);
}

void Fixed::setRawBits(int const raw)
{
    this->_rawbits = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_rawbits / (1 << this->_fractionalBits));
}
int Fixed::toInt(void) const
{
    return (this->_rawbits >> this->_fractionalBits);
}
std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
    out << obj.toFloat();
    return (out);
};