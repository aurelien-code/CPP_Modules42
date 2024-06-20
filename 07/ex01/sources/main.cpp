#include <iostream>
#include "iter.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(array) / sizeof(array[0]);

	void (*printInt)(int&) = printval<int>;

    std::cout << "Original array: \n";
    iter(array, length, printInt);
    std::cout << std::endl;

	std::cout << "Incremented array: \n";
    iter(array, length, increment);
	iter(array, length, printInt);

    std::cout << std::endl;
	return 0;
}
