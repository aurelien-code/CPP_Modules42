#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): 
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

Form::Form(const Form &copy): 
    _name(copy._name), 
    _gradeToSign(copy._gradeToSign), 
    _gradeToExecute(copy._gradeToExecute),
    _isSigned(copy._isSigned)
{
}

Form &Form::operator=(const Form &ref)
{
   if (this != &ref)
   {
        this->_isSigned = ref._isSigned;
   }
   return (*this);
}

Form::~Form()
{
    return ;
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::getIsSigned(void) const
{
    return this->_isSigned;
}

int Form::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

bool Form::beSigned(Bureaucrat &bureaucrat)
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

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form : " << form.getName() 
		<< "\n\tis signed : " << (form.getIsSigned() ? "yes" : "no")
		<< "\n\trequired grade to sign : " << form.getGradeToSign() 
		<< "\n\trequired grade to execute : " << form.getGradeToExecute();
	return (os);
}
