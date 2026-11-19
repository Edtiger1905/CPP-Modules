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
    _rawBits = other.getRawBits();
    return (*this);
}
int Fixed::getRawBits(void) const
{
    return (this->_rawBits);
}
float Fixed::toFloat(void) const
{
    return ((float)this->_rawBits / (1 << this->_fractionalBits));
}
int Fixed::toInt(void) const
{
    return (this->_rawBits >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
    out << obj.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed temp;
    temp.setRawBits(this->getRawBits() + other.getRawBits());
    return (temp);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed temp;
    temp.setRawBits(this->getRawBits() - other.getRawBits());
    return (temp);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    long long n = static_cast<long long>(this->getRawBits()) * other.getRawBits();
    Fixed temp;
    temp.setRawBits(n >> temp._fractionalBits);
    return(temp);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed temp;
    long long n = (static_cast<long long>(this->getRawBits()) << temp._fractionalBits) / other.getRawBits();
    temp.setRawBits(n);
    return (temp);
}

Fixed &Fixed::operator++()
{
    ++_rawBits;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _rawBits++;
    return (tmp);
}
Fixed &Fixed::operator--()
{
    --_rawBits;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _rawBits--;
    return (tmp);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
    if(n1 < n2)
        return (n1);
    return (n2);
}
Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
    if (n1 < n2)
        return (n1);
    return (n2);
}
const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}
Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}