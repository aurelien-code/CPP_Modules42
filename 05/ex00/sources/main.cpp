#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    //Test empty constructor
    {
        std::cout << "\t~~~Test empty constructor~~~" << std::endl;
        try {
            Bureaucrat aurelien;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    //Test good constructor
    {
        std::cout << "\t~~~Test good constructor~~~" << std::endl;
        try {
            Bureaucrat benjamin("Bob", 1);
            std::cout << benjamin << std::endl;

            if (benjamin.getName() != "Bob") {
                std::cerr << "Test failed: Name getter returned wrong value" << std::endl;
            }
            if (benjamin.getGrade() != 1) {
                std::cerr << "Test failed: Grade getter returned wrong value" << std::endl;
            }
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
        
    // Test invalid grade
    {
        std::cout << "\t~~~Test invalid grades (0, 151)~~~" << std::endl;
        try {
            Bureaucrat invalid("Invalid", 0);
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        try {
            Bureaucrat invalid("Invalid", 151);
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }

    //Test invalid increment
    {
        std::cout << "\t~~~Test invalid increment, dec ; inc ; inc~~~" << std::endl;
        try
        {
            Bureaucrat highest("Highest", 1);
            highest.decrementGrade();
            std::cout << highest << std::endl;
            highest.incrementGrade();
            highest.incrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    //Test invalid decrement
    {
        std::cout << "\t~~~Test invalid decrement, inc ; dec ; dec~~~" << std::endl;
        try
        {
            Bureaucrat lowest("Lowest", 150);
            lowest.incrementGrade();
            std::cout << lowest << std::endl;
            lowest.decrementGrade();
            lowest.decrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    //Test the assignement operator
    {
        std::cout << "\t~~~Test assignement operator~~~" << std::endl;
        try {
            Bureaucrat assign_op = Bureaucrat("ASOP", 55);
            Bureaucrat assign_op2 = Bureaucrat("ASSOP2", 110);
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
    }
	return (0);
}
