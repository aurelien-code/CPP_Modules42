#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &src);
        Intern &operator=(Intern const &src);
        ~Intern();

        AForm*	newShrubbery( std::string target );
        AForm*	newPresidential( std::string target );
        AForm*	newRobotomy( std::string target );
        AForm *makeForm(std::string formName, std::string target);
};

#endif