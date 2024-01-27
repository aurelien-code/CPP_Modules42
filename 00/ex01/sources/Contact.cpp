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

std::string Contact::get_first_name() const {
	return _first_name;
}

std::string Contact::get_last_name() const{ 
	return _last_name;
}

std::string Contact::get_nickname() const{ 
	return _nickname;
}

std::string Contact::get_phonenumber() const{ 
	return _phonenumber;
}

std::string Contact::get_darkest_secret() const{
	return _darkest_secret;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << "First Name: " << contact.get_first_name() << std::endl;
	os << "Last Name: " << contact.get_last_name() << std::endl;
	os << "Nickname: " << contact.get_nickname() << std::endl;
	os << "Phonenumber: " << contact.get_phonenumber() << std::endl;
	os << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
    return os;
}