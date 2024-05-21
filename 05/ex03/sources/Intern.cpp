#include "Intern.hpp"
#include <iostream>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}
Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern &Intern::operator=(Intern const &src)
{
	(void)src;
    return (*this);
}

Intern::~Intern()
{
}

AForm*	Intern::newShrubbery( std::string target )
{
	return(new ShrubberyCreationForm(target));
}
AForm*	Intern::newPresidential( std::string target )
{
	return(new PresidentialPardonForm(target));
}
AForm*	Intern::newRobotomy( std::string target )
{
	return(new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;
    std::string	s[3] = {
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"
        };
	AForm* (Intern::*p[3])(std::string) = {
        &Intern::newShrubbery,
        &Intern::newRobotomy,
        &Intern::newPresidential
    };

	while (i < 4 && s[i].compare(formName) != 0)
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << s[i] << std::endl;
		return((this->*p[i])(target));
	}
	else
		std::cout << "Error: " << formName << " is not a valid name for a form!" << std::endl;
	return (NULL);
}
