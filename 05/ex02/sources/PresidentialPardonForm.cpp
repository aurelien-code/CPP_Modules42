#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): AForm(src)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return ;
}

void PresidentialPardonForm::doAction(void) const
{
    std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
