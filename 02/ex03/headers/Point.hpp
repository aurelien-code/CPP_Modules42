
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const Point &p);
		Point(const float &x, const float &y);
		~Point();
		Point &operator=(const Point &p);
		Fixed getX() const;
		Fixed getY() const;
};

#endif