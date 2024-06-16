#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm & operator=(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();

        void doAction(void) const;
};

#endif