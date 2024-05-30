#include <iostream>
#include "Array.hpp"

int main()
{
	try {
        Array<int> arr1;
        Array<int> arr2(5);

        std::cout << "arr2 size: " << arr2.size() << std::endl;
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";  // Should print default-initialized values (0 for int)
        }
        std::cout << std::endl;

        arr2[2] = 42;  // Modify an element
        Array<int> arr3(arr2);  // Copy constructor
        arr2[2] = 0;  // Modify the original after copying

        std::cout << "arr2: ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "arr3: ";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;

        // Test assignment operator
        Array<int> arr4 = arr2;
        arr2[1] = 7;  // Modify the original after assigning

        std::cout << "arr4: ";
        for (unsigned int i = 0; i < arr4.size(); ++i) {
            std::cout << arr4[i] << " ";
        }
        std::cout << std::endl;

        // Test out-of-bounds access
        std::cout << arr2[10] << std::endl;  // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}
