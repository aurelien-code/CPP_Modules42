
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Point &p);
		Point(const float x_f, const float y_f);
		~Point();
		Point &operator=(const Point &p);
		Fixed getX() const;
		Fixed getY() const;
};

#endif