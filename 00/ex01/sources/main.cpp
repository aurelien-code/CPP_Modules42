#include <iostream>
#include "PhoneBook.hpp"
#include <string>
#include <sstream>

// Display a formatted list of contacts with their index

int main()
{
	PhoneBook pb;
	std::string cmd;

    std::cout << "My Awesome PhoneBook" << std::endl;    
    while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (std::cin.eof())
			return 0;
		
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break;
		else
		{
			std::cout << "Error: command not found, commands available (case sensitive): " << std::endl;
			std::cout << "\t * ADD" << std::endl;
			std::cout << "\t * SEARCH" << std::endl;
			std::cout << "\t * EXIT" << std::endl;
		}
	}

	return (0);
}
