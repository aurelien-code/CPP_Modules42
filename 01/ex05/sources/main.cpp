#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string level = argv[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "Wrong argument" << std::endl;
		return (1);
	}
	Harl harlito = Harl();
	harlito.complain(level);
}