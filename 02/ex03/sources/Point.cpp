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

bool Point::bsp(const Point &a, const Point &b, const Point &c, Point const point) const {
	Fixed areaABC = (a.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-b.getY()))/2;
    Fixed areaPAB = (point.getX()*(a.getY()-b.getY()) + a.getX()*(b.getY()-point.getY()) + b.getX()*(point.getY()-a.getY()))/2;
    Fixed areaPBC = (point.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-point.getY()) + c.getX()*(point.getY()-b.getY()))/2;
    Fixed areaPCA = (point.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-point.getY()) + a.getX()*(point.getY()-c.getY()))/2;
    return (areaABC.getRawBits() == areaPAB.getRawBits() + areaPBC.getRawBits() + areaPCA.getRawBits());
}
