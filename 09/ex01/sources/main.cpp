#include <iostream>
#include "RPN.hpp"


/*
	Knowed problems :
		- Doesnt handle float numbers 
		- Doesnt check if a number is < 10 >
*/
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid argument" << std::endl;
		return (1);
	}
	std::string av1_str(av[1]);
	
	RPN rpn(av1_str);
	rpn.calculate();
	return (0);
}
