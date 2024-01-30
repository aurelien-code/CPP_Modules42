#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

float	vect_product(Point const a, Point const b, Point const point) {
	return (((a.getX()
    -   point.getX()) * (b.getY() - point.getY())
    -   (a.getY() - point.getY()) * (b.getX()
    -   point.getX())).toFloat());
}

//Create the function for a line equation
//Check if the point is on the line

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
    float abp = vect_product(a, b, point);
    float bcp = vect_product(b, c, point);
    float cap = vect_product(c, a, point);

	if (!abp || !bcp || !cap)
		return (0);
	else if ((abp > 0 && bcp > 0 && cap > 0) || (!(abp <= 0) && !(bcp <= 0) && !(cap <= 0)))
    {
		return (1);
    }
	else
		return (0);
}