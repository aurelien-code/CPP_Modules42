#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	_value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = value * (1 << _bits);
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" <<  std::endl;
	_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(Fixed const &ref)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ref;	
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
    return os;
}

Fixed &Fixed::operator=(Fixed const &ref)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = ref.getRawBits();
	return (*this);
}

Fixed &Fixed::operator+(Fixed const &ref)
{
	// std::cout << "Addition operator called" << std::endl;
	this->_value += ref.getRawBits();
	return (*this);
}

Fixed &Fixed::operator-(Fixed const &ref)
{
	// std::cout << "Subtraction operator called" << std::endl;
	this->_value -= ref.getRawBits();
	return (*this);
}

Fixed &Fixed::operator*(Fixed const &ref)
{
	// std::cout << "Multiplication operator called" << std::endl;
	this->_value *= ref.toFloat();
	return (*this);
}

Fixed &Fixed::operator/(Fixed const &ref)
{
	// std::cout << "Division operator called" << std::endl;
	this->_value /= ref.toFloat();
	return (*this);
}

bool Fixed::operator>(Fixed const &ref)
{
	return (this->_value > ref.getRawBits());
}

bool Fixed::operator>(Fixed const &ref) const
{
	return (this->_value > ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref)
{
	return (this->_value < ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref) const
{
	return (this->_value < ref.getRawBits());
}

bool Fixed::operator>=(Fixed const &ref)
{
	return (this->_value >= ref.getRawBits());
}

bool Fixed::operator<=(Fixed const &ref)
{
	return (this->_value <= ref.getRawBits());
}

bool Fixed::operator==(Fixed const &ref)
{
	return (this->_value == ref.getRawBits());
}

bool Fixed::operator!=(Fixed const &ref)
{
	return (this->_value != ref.getRawBits());
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();
	return (*this);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? (Fixed &)a : (Fixed &)b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int raw)
{
	(void)raw; 
}

int Fixed::toInt(void) const
{
	return _value >> _bits;
}

float Fixed::toFloat(void) const
{
	return (float)(_value) / (float)(1 << _bits);
}
