#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &p) : x(p.getX()), y(p.getY()) {}

Point::Point(const float x_f, const float y_f) : x(Fixed(x_f)), y(Fixed(y_f)) {}

Point::~Point() {}

Point &Point::operator=(const Point &p)
{
	(void)p;
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