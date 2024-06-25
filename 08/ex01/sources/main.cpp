#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
	try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;  // Output should be 2
        std::cout << sp.longestSpan() << std::endl;   // Output should be 14

        std::vector<int> moreNumbers;
		moreNumbers.push_back(1);
		moreNumbers.push_back(2);
		moreNumbers.push_back(3);
		moreNumbers.push_back(4);
		moreNumbers.push_back(5);
        Span sp2 = Span(10);
        sp2.addNumbers(moreNumbers.begin(), moreNumbers.end());
        std::cout << sp2.shortestSpan() << std::endl; // Output should be 1
        sp2.addNumbers(moreNumbers.begin(), moreNumbers.begin() + 2);
        std::cout << sp2.shortestSpan() << std::endl; // Output should be 0
        std::cout << sp2.longestSpan() << std::endl;  // Output should be 4

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	return (0);
}
