#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::string input_file_path;
	
	if (ac != 2)
	{
		std::cout << "Invalid number of argument, no file provided !" << std::endl;
		return (1);
	}
	
	input_file_path = av[1];
	BitcoinExchange exchange(input_file_path);
	try
	{
		exchange.run();
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
