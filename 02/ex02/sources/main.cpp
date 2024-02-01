#include <iostream>
#include "Fixed.hpp"

int main(void)
{

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << Fixed::min(a,b) << std::endl;

	Fixed c(-2.4f);
	Fixed d(-4.0f);
	std::cout << "c:\t" << (c) << std::endl;
	std::cout << "d:\t" << (d) << std::endl;
	std::cout << "c*d:\t" << c * d << std::endl;
	std::cout << "c/d:\t" << c / d << std::endl;
	std::cout << "c+d:\t" << c + d << std::endl;
	std::cout << "c-d:\t" << c - d << std::endl;
	std::cout << "c++:\t" << c++ << std::endl;
	std::cout << "++c:\t" << ++c << std::endl;
	std::cout << "c--:\t" << c-- << std::endl;
	std::cout << "--c:\t" << --c << std::endl;
	std::cout << "max:\t" << Fixed::max(c,d) << std::endl;
	std::cout << "min:\t" << Fixed::min(c,d) << std::endl;

	return 0;
}