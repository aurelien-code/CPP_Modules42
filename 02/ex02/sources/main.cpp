#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	// int b = (50.0f) * (1 << 8);
	// int c = b >> 8;
	// std::cout << b << " <--- float_to_int" << std::endl; //10859.5 == RAW == _VALUE
	// std::cout << c << " <--- partie int" << std::endl;
	// std::cout << (float)(b) / (float)(1 << 8) << " <---- int_to_float" << std::endl; //fl
	
	// a = Fixed (42.42f);
	// std::cout << "AA = " << a;
	// int b = a.toInt();
	// std::cout << std::endl << "BB = " <<  b << std::endl;
	return 0;
}