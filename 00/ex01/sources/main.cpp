#include <iostream>
#include "PhoneBook.hpp"

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
	}
	return (0);
}