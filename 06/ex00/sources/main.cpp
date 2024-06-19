#include <iostream>
#include "ScalarConverter.hpp"
#include <typeinfo>

#define YELLOW  "\x1B[33m"
#define WHITE   "\x1B[37m"
#define BLUE    "\x1b[34m"

void testsCases(const char* cases[], int size, std::string testsType)
{
	std::cout << YELLOW << "~~~Testing " << testsType << " CASES~~~" << WHITE << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << BLUE << "input value : " << cases[i] << WHITE << std::endl;
		ScalarConverter::convert(cases[i]);
	}
}

int main(int ac, char **av)
{
	const char *testsSpecials[6] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
	const char *testsInt[8] = {"0", "42", "-42", "2147483647", "-2147483648", "127", "31", "128"};
	const char *testsChar[4] = {"a", "Z", "!", "~"};
	const char *testsFloat[10] = {"0.0", "-0.0", "3.14", "-3.14", "1.0f", "-1.0f", "1.23e10", "340282346638528859811704183484516925440.0f", "-340282346638528859811704183484516925440.0f"};
	
	testsCases(testsSpecials, 6, "Specials");
	testsCases(testsInt, 8, "Int");
	testsCases(testsChar, 4, "Char");
	testsCases(testsFloat, 9, "Double/Float");

	if (ac == 2)
		ScalarConverter::convert(av[1]);
	return (0);
}
