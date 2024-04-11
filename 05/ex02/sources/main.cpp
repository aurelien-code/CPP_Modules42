#include <iostream>
#include "Bureaucrat.hpp"
#include <Form.hpp>


/*
    TODO : 
        - Add tests for Form
        - Check valgrind for leaks / errors
*/
int main()
{
    Bureaucrat Aurelien("Aurelien", 1);
    Bureaucrat Bob("Bob", 75);

    Form contract("Contract", 2, 1);

    std::cout << "\t~~~Form should not be signed~~~" << std::endl;
    std::cout << contract << std::endl;
    std::cout << "\t~~~Bureaucrat with ok grade signs~~~" << std::endl;
    try
    {
        contract.beSigned(Aurelien);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\t~~~Form should be signed~~~" << std::endl;
    std::cout << contract << std::endl;
    std::cout << "\t~~~Bureaucrat tries to sign a signed form~~~" << std::endl;
    try
    {
        contract.beSigned(Aurelien);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\t~~~Bureaucrat does not have a grade to sign~~~" << std::endl;
    Form contract_not_signable("FakeContract", 2, 1);
    try
    {
        contract.beSigned(Bob);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

	return (0);
}
