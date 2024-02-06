#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

int main(void)
{
	//	Triangle
	Point a((438.9f), (38.99f));
	Point b((616.60f), (612.85f));
	Point c((332.40f), (514.85f));

	Point A_pt(406.0f, 328.0f);
	bool result_A = bsp(a, b, c, A_pt); // true

	Point E_pt(302.0f, 324.0f);
	bool result_E = bsp(a, b, c, E_pt); // false

	Point F_pt(603.7899f, 236.6299f);
	bool result_F = bsp(a, b, c, F_pt); // false

	Point G_pt(517.2942f, 489.7899f);
	bool result_G = bsp(a, b, c, G_pt); // true

	Point a_a(0, 10);
	Point b_b(10, 0);
	Point c_c(0,0);
	Point H_pt(5, 0);
	bool result_H = bsp(a_a, b_b, c, H_pt); // false

	std::cout << "Point A -> result_true: " << result_A << "\n";
	std::cout << "Point E -> result_false: " << result_E << "\n";
	std::cout << "Point F -> result_false: " << result_F << "\n";
	std::cout << "Point G -> result_true: " << result_G << "\n";
	std::cout << "Point H -> result_false: " << result_H << "\n";

	// SECOND TRIANGLE
	// Point a((2.28f), (-3.32f));
	// Point b((-4.54f), (-4.44f));
	// Point c((-1.0f), (4.0f));

	// Point D(-0.94f, -0.74f);
	// bool result_A = bsp(a, b, c, D); // true

	// Point E(-7.0f, 2.76f);
	// bool result_E = bsp(a, b, c, E); // false

	// Point F_pt(1.4f, 4);
	// bool result_F = bsp(a, b, c, F_pt); // false

	// std::cout << "Point A -> result_true: " << result_A << "\n";
	// std::cout << "Point E -> result_false: " << result_E << "\n";
	// std::cout << "Point F -> result_false: " << result_F << "\n";

	return 0;
}