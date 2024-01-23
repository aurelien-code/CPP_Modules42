#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address held by str_ptr: " << str_ptr << std::endl;
	std::cout << "Address held by str_ref: " << &str_ref << std::endl;

	std::cout << "Valueof str: " << str << std::endl;
	std::cout << "Value pointed by str_ptr: " << *str_ptr << std::endl;
	std::cout << "Value pointed by str_ref: " << str_ref << std::endl;
}