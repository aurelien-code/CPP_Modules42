#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	_value = 0;
	 std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value * (1 << 8);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" <<  std::endl;
	_value = value * (1 << 8);
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
	this->_value = ref.getRawBits();
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
	return (_value);
}

void Fixed::setRawBits(int raw)
{
	(void)raw; 
}

int Fixed::toInt(void) const
{
	return _value >> 8;
}

float Fixed::toFloat(void) const
{
	return (float)(_value) / (float)(1 << 8);
}
