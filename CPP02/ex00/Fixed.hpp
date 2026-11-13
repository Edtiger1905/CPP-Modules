#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int _rawbits;
    static const int _fnum = 8;

public:
    Fixed();
    Fixed(Fixed& op); //costruttore di copia
    Fixed &operator=(const Fixed& op);
    int getRawBits(void)const;
    void setRawBits(int const raw);
    ~Fixed();
};

#endif