#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return ;
}

void RobotomyRequestForm::doAction(void) const
{
    static bool r = true;
    if (r)
    {
        std::cout << "*drilling noises* " << this->getName() << " has been robotomized." << std::endl;
    }
    else
    {
        std::cout << "*drilling noises* " << this->getName() << " robotomization failed." << std::endl;
    }
    r = !r;
}
