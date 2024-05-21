#include <iostream>
#include "Bureaucrat.hpp"

#define YELLOW  "\x1B[33m"
#define WHITE   "\x1B[37m"

int main()
{
    try {
        std::cout << YELLOW << "=> Bureaucrat Daniel with grade 151 <=" << WHITE << std::endl;
        Bureaucrat daniel("Daniel", 151);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << YELLOW << "=> Bureaucrat Louis with grade -1 <=" << WHITE << std::endl;
        Bureaucrat louis("Louis", -1);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << YELLOW << "=> Decrement Bureaucrat with a 150 grade <=" << WHITE << std::endl;
        Bureaucrat bilal("Bilal", 150);
        bilal.decrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << YELLOW << "=> Increment Bureaucrat with a 1 grade <=" << WHITE << std::endl;
        Bureaucrat james("James", 1);
        james.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << YELLOW << "=> All good operations tests <=" << WHITE << std::endl;
        Bureaucrat jerem("Jerem", 22);
        std::cout << jerem << std::endl;
        jerem.decrementGrade();
        std::cout << jerem << std::endl;
        jerem.incrementGrade();
        std::cout << jerem << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << YELLOW << "=> Test assignement operator <=" << WHITE << std::endl;
        Bureaucrat assign_op = Bureaucrat("ASOP", 55);
        Bureaucrat assign_op2 = Bureaucrat("ASSOP_2", 110);
        std::cout << assign_op << std::endl;
        std::cout << assign_op2 << std::endl;
        std::cout << "assign_op = assign_op2" << std::endl;
        assign_op = assign_op2;
        std::cout << assign_op << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
	return (0);
}
