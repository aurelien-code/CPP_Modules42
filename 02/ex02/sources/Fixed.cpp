#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(Fixed const &ref)
{
	*this = ref;	
}

Fixed::~Fixed(void)
{
}


Fixed &Fixed::operator=(Fixed const &ref)
{
	if (this != &ref)
	{
		this->setRawBits(ref.getRawBits());
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator+(Fixed const &ref) const
{
	Fixed sum;

	sum.setRawBits(this->getRawBits() + ref.getRawBits());
	return (sum);
}

Fixed Fixed::operator-(Fixed const &ref) const
{
	Fixed diff;

	diff.setRawBits(this->getRawBits() - ref.getRawBits());
	return (diff);
}

Fixed Fixed::operator*(Fixed const &ref) const
{
	Fixed result;

	result.setRawBits(this->toFloat() * ref.toFloat());
	return (result);
}

Fixed Fixed::operator/(Fixed const &ref) const
{
	Fixed quotient;

	quotient.setRawBits(this->toFloat() / ref.toFloat());
	return (quotient);
}

bool Fixed::operator>(Fixed const &ref)
{
	return (this->getRawBits() > ref.getRawBits());
}

bool Fixed::operator>(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref)
{
	return (this->getRawBits() < ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool Fixed::operator>=(Fixed const &ref)
{
	return (this->_value >= ref.getRawBits());
}

bool Fixed::operator<=(Fixed const &ref)
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool Fixed::operator==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

bool Fixed::operator!=(Fixed const &ref)
{
	return (this->getRawBits() != ref.getRawBits());
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
	return this->_value;
}

void Fixed::setRawBits(int raw)
{
	this->_value = raw; 
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_value / (float)(1 << this->_bits)));
}