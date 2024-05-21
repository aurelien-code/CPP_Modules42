#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute): 
    _name(name),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute),
    _isSigned(false)
{
    if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
        throw GradeTooLowException();
    if (this->_gradeToSign < 1 || this->_gradeToSign < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &copy): 
    _name(copy._name), 
    _gradeToSign(copy._gradeToSign), 
    _gradeToExecute(copy._gradeToExecute),
    _isSigned(copy._isSigned)
{
}

AForm &AForm::operator=(const AForm &ref)
{
   if (this != &ref)
   {
        this->_isSigned = ref._isSigned;
   }
   return (*this);
}

AForm::~AForm()
{
    return ;
}

std::string AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getIsSigned(void) const
{
    return this->_isSigned;
}

int AForm::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

bool AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < getGradeToSign())
    {
		this->_isSigned = true;
        return true;
    }
	else
	{
		throw GradeTooLowException();
	}
    return false;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    else
       doAction(); 
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form : " << form.getName() 
		<< "\n\tis signed : " << (form.getIsSigned() ? "yes" : "no")
		<< "\n\trequired grade to sign : " << form.getGradeToSign() 
		<< "\n\trequired grade to execute : " << form.getGradeToExecute();
	return (os);
}
