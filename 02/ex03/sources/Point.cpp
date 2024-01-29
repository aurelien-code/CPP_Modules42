#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &p) : x(p.x), y(p.y) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::~Point() {}

Point &Point::operator=(const Point &p)
{
	if (this != &p)
	{
		this->x = p.x;
		this->y = p.y;
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

Fixed Point::get_abs(Fixed value) const
{
	if (value < 0)
	{
		return value * -1;
	}
	else
		return value;
}
#include <iostream>
bool Point::bsp(const Point &a, const Point &b, const Point &c, Point const point) const {
	Fixed areaABC = get_abs(a.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-b.getY()))/2.0f;
	Fixed areaPAB = get_abs(point.getX()*(a.getY()-b.getY()) + a.getX()*(b.getY()-point.getY()) + b.getX()*(point.getY()-a.getY()))/2.0f;
	Fixed areaPBC = get_abs(point.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-point.getY()) + c.getX()*(point.getY()-b.getY()))/2.0f;
	Fixed areaPCA = get_abs(point.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-point.getY()) + a.getX()*(point.getY()-c.getY()))/2.0f;
	
	// std::cout << "a_ABC = " << areaABC.getRawBits() << std::endl;
	// std::cout << "a_PAB = " << areaPAB << std::endl;
	// std::cout << "a_PBC = " << areaPBC << std::endl;
	// std::cout << "a_PCA = " << areaPCA << std::endl; 
	// std::cout << "somme = " << (areaPAB + areaPBC + areaPCA).getRawBits() << std::endl;
	// std::cout << "False" << std::endl;
	if (areaABC.getRawBits() == (areaPAB + areaPBC + areaPCA).getRawBits())
	{
		return true;
	}
	else
	{
		return false;
	}
}
