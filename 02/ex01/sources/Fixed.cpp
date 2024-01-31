#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value * (1 << _bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" <<  std::endl;
	this->_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;	
}

Fixed &Fixed::operator=(Fixed const &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
    return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_bits;
}

float Fixed::toFloat(void) const
{
	return (float)(this->_value) / (float)(1 << this->_bits);
}
