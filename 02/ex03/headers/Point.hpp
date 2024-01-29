
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
		Fixed get_abs(Fixed value) const;
	public:
		Point();
		Point(const Point &p);
		Point(const Fixed &x, const Fixed &y);
		~Point();
		Point &operator=(const Point &p);
		Fixed getX() const;
		Fixed getY() const;
		
		bool bsp(const Point &a, const Point &b, const Point &c, Point const point) const;

};

#endif