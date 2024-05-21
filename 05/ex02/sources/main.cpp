
#include <iostream>
#include <stdexcept>
#include <cassert>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define YELLOW "\x1B[33m"
#define WHITE "\x1B[37m"

void testInitialization() {
    try {
        ShrubberyCreationForm shrubbery("garden");
        assert(shrubbery.getGradeToSign() == 145);
        assert(shrubbery.getGradeToExecute() == 137);
        assert(shrubbery.getName() == "garden");

        RobotomyRequestForm robotomy("robot");
        assert(robotomy.getGradeToSign() == 72);
        assert(robotomy.getGradeToExecute() == 45);
        assert(robotomy.getName() == "robot");

        PresidentialPardonForm pardon("criminal");
        assert(pardon.getGradeToSign() == 25);
        assert(pardon.getGradeToExecute() == 5);
        assert(pardon.getName() == "criminal");
    } catch (std::exception& e) {
        std::cerr << "Initialization test failed: " << e.what() << std::endl;
    }
}

void testSigning() {
    try {
        Bureaucrat highRanker("Alice", 1);
        ShrubberyCreationForm shrubbery("garden");
        highRanker.signForm(shrubbery);
        assert(shrubbery.getIsSigned());

        RobotomyRequestForm robotomy("robot");
        highRanker.signForm(robotomy);
        assert(robotomy.getIsSigned());

        PresidentialPardonForm pardon("criminal");
        highRanker.signForm(pardon);
        assert(pardon.getIsSigned());

        Bureaucrat lowRanker("Bob", 150);
        ShrubberyCreationForm shrubbery2("park");
        lowRanker.signForm(shrubbery2);
    } catch (std::exception& e) {
        std::cerr << "Signing test failed: " << e.what() << std::endl;
    }
}

void testExecution() {
    try {
        Bureaucrat highRanker("Alice", 1);
        ShrubberyCreationForm shrubbery("garden");
        shrubbery.beSigned(highRanker);
        highRanker.executeForm(shrubbery);

        RobotomyRequestForm robotomy("robot");
        robotomy.beSigned(highRanker);
        highRanker.executeForm(robotomy);
        highRanker.executeForm(robotomy);

        PresidentialPardonForm pardon("criminal");
        pardon.beSigned(highRanker);
        highRanker.executeForm(pardon);

        Bureaucrat lowRanker("Bob", 150);
        ShrubberyCreationForm shrubbery2("park");
        shrubbery2.beSigned(highRanker);
        lowRanker.executeForm(shrubbery2);
    } catch (std::exception& e) {
        std::cerr << "Execution test failed: " << e.what() << std::endl;
    }
}

int main() 
{
	std::cout << YELLOW << "initialization tests" << WHITE << std::endl;
    testInitialization();
	std::cout << YELLOW << "signing tests" << WHITE << std::endl;
    testSigning();
	std::cout << YELLOW << "execution tests" << WHITE << std::endl;
    testExecution();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

