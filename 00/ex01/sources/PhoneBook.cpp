#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits>

PhoneBook::PhoneBook()
{
	_nb_of_contacts = 0;
	_phonebook_size = 0;
}

PhoneBook::~PhoneBook()
{
}


bool PhoneBook::is_valid_phonenumber(std::string phone)
{
	int i = 0;

	if (phone[i] == '+')
		i++;
	while (phone[i])
	{
		if (!std::isdigit(phone[i]))
			return false;
		i++;
	}
	return true;
}

std::string PhoneBook::truncateAndFormat(std::string str)
{
    if (str.size() <= 10) {
        return str;
    }
    return str.substr(0, 9) + ".";
}

void PhoneBook::add()
{
	std::string fname, lname, nname, phone, secret;

	std::cout << "Your firstname: ";
	std::cin >> fname;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cout << "Your lastname: ";
	std::cin >> lname;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cout << "Your nickname: ";
	std::cin >> nname;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cout << "Your phonenumber: ";
	std::cin >> phone;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Your darkest secret: ";
	std::getline(std::cin, secret);
				
	if (secret.empty())
		std::cout << "Error: the contact cannot have empty fields" << std::endl;
	else if (!is_valid_phonenumber(phone))
		std::cout << "Error: phonenumber format is invalid" << std::endl;
	else
	{
		if (_nb_of_contacts >= 8)
			_nb_of_contacts = 0;
		else 
		{
			_contacts[_nb_of_contacts].set_first_name(fname);
			_contacts[_nb_of_contacts].set_last_name(lname);
			_contacts[_nb_of_contacts].set_nickname(nname);
			_contacts[_nb_of_contacts].set_phonenumber(phone);
			_contacts[_nb_of_contacts].set_darkest_secret(secret);
			_nb_of_contacts++;
		}
		if (_phonebook_size < 8)
			_phonebook_size++;
	}
}

void PhoneBook::search()
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < _phonebook_size; ++i) {
        std::cout << "|" << std::setw(10) << i + 1
                  << "|" << std::setw(10) << truncateAndFormat(_contacts[i].get_first_name())
                  << "|" << std::setw(10) << truncateAndFormat(_contacts[i].get_last_name())
                  << "|" << std::setw(10) << truncateAndFormat(_contacts[i].get_nickname())
                  << "|" << std::endl;
    }
	
	int idx;
	std::cout << "Enter the index of the contact you want : ";
	std::cin >> idx;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		if (idx > 7 || idx < 1 || idx > _phonebook_size)
		{
			std::cout << "Error: index of contact out of range" << std::endl;
			return ;
		}
		else
			std::cout << _contacts[idx - 1];
	}
}