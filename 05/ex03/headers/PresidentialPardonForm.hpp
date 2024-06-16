#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm & operator=(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();

        void doAction(void) const;
};

#endif