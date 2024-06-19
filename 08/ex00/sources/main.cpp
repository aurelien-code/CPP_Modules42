#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	// Test with a vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    std::vector<int>::iterator it = easyfind(vec, 3);
    if (it != vec.end()) {
        std::cout << "Found value: " << *it << " in vector" << std::endl;
    } else {
        std::cout << "Value not found in vector" << std::endl;
    }

    it = easyfind(vec, 10);
    if (it != vec.end()) {
        std::cout << "Found value: " << *it << " in vector" << std::endl;
    } else {
        std::cout << "Value not found in vector" << std::endl;
    }

    // Test with a list
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    std::list<int>::iterator itList = easyfind(lst, 4);
    if (itList != lst.end()) {
        std::cout << "Found value: " << *itList << " in list" << std::endl;
    } else {
        std::cout << "Value not found in list" << std::endl;
    }

    itList = easyfind(lst, 7);
    if (itList != lst.end()) {
        std::cout << "Found value: " << *itList << " in list" << std::endl;
    } else {
        std::cout << "Value not found in list" << std::endl;
    }
	return (0);
}
