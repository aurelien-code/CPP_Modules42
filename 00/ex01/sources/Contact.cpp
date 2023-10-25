#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_first_name(std::string val)
{
	_first_name = val;
}

void Contact::set_last_name(std::string val)
{
	_last_name = val;
}

void Contact::set_nickname(std::string val)
{
	_nickname = val;
}

void Contact::set_phonenumber(std::string val)
{
	_phonenumber = val;
}

void Contact::set_darkest_secret(std::string val)
{
	_darkest_secret = val;
}

std::string Contact::get_first_name() {
	return _first_name;
}

std::string Contact::get_last_name() { 
	return _last_name;
}

std::string Contact::get_nickname() { 
	return _nickname;
}

std::string Contact::get_phonenumber() { 
	return _phonenumber;
}

std::string Contact::get_darkest_secret() {
	return _darkest_secret;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << "First Name: " << contact._first_name << std::endl;
	os << "Last Name: " << contact._last_name << std::endl;
	os << "Nickname: " << contact._nickname << std::endl;
	os << "Phonenumber: " << contact._phonenumber << std::endl;
	os << "Darkest secret: " << contact._darkest_secret << std::endl;
    return os;
}