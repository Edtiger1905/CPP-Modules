#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

Fixed::~Fixed(){
    std::cout << "Distructor called" << std::endl;
}

Fixed::Fixed(Fixed& op){
    std::cout << "Copy constructor called" << std::endl;
    *this = op;
}

Fixed &Fixed::operator=(const Fixed& op){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &op)
        _rawbits = op.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_rawbits);
}

void Fixed::setRawBits(int const raw){
    _rawbits = raw;
}

