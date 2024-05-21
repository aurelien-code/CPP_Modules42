#include <iostream>
#include "ScalarConverter.hpp"
#include <typeinfo>

//Knowed issues :
/*
	- char type doesnt seems to work.
	- if 9.9, i'm not sure the result is as exepted
*/

int main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	return (0);
}