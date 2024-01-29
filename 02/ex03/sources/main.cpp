#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Fixed A_x(406);
	Fixed A_y(328);

	Fixed E_x(302);
	Fixed E_y(324);

	Fixed F_x(603.7899f);
	Fixed F_y(236.6299f);

	Fixed G_x(517.2942f);
	Fixed G_y(489.7899f);

	Fixed H_x(508.740f);
	Fixed H_y(264.530f);
	//Triangle
	Point a(Fixed(438.9f), Fixed(38.99f));
	Point b(Fixed(616.60f), Fixed(612.85f));
	Point c(Fixed(332.40f), Fixed(514.85f));

	bool result_A = b.bsp(a, b, c, Point(A_x, A_y)); // true
	bool result_E = b.bsp(a, b, c, Point(E_x, E_y)); // false
	bool result_F = b.bsp(a, b, c, Point(F_x, F_y)); // false
	bool result_G = b.bsp(a, b, c, Point(G_x, G_y)); // true
	bool result_H = b.bsp(a, b, c, Point(H_x, H_y)); // false
	std::cout << "Point A -> result_true: " << result_A << "\n";
	std::cout << "Point E -> result_false: " << result_E << "\n";
	std::cout << "Point F -> result_false: " << result_F << "\n";
	std::cout << "Point G -> result_true: " << result_G << "\n";
	std::cout << "Point H -> result_false: " << result_H << "\n";
	return 0;
}