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
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;
	std::cout << c + d << std::endl;
	std::cout << Fixed::max(c,d) << std::endl;
	std::cout << Fixed::min(c,d) << std::endl;
	return 0;
}