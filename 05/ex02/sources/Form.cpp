#include "Form.hpp"

Form::Form(): 
	_name(""), _requiredGradeToExecute(0), _requiredGradeToSign(0), _signed(false)
{
	throw std::invalid_argument("Form cannot be initialized without arguments");
}

Form::Form(const std::string name, const int gradeToSign, const int GradeToExecute): 
	_name(name), _requiredGradeToExecute(GradeToExecute), _requiredGradeToSign(gradeToSign), _signed(false)
{
	if (getRequiredGradeToSign() > 150 || getRequiredGradeToExecute() > 150)
	{
		throw GradeTooLowException();
	}
	else if (getRequiredGradeToSign() < 1 || getRequiredGradeToExecute() < 1)
	{
		throw GradeTooHighException();
	}
}

Form::Form(const Form &copy):
	_name(copy.getName()), _requiredGradeToExecute(copy.getRequiredGradeToExecute()), _requiredGradeToSign(copy.getRequiredGradeToSign()), _signed(copy.getSigned())
{
	*this = copy;
}

Form &Form::operator=(const Form &ref)
{
	if (this != &ref)
	{
		this->_signed = ref.getSigned();
	}
	return (*this);
}

Form::~Form()
{
	return ;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getRequiredGradeToExecute() const
{
	return this->_requiredGradeToExecute;
}

int Form::getRequiredGradeToSign() const
{
	return this->_requiredGradeToSign;
}


bool Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredGradeToSign())
	{
		bureaucrat.signForm(false, "Grade too low");
		throw GradeTooLowException();
		return false;
	}
	if (this->getSigned())
	{
		bureaucrat.signForm(false, "Form already signed");
		return false;
	}
	else
	{
		this->_signed = true;
		bureaucrat.signForm(true, this->getName());
		return true;
	}
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
	os << "FORM DETAILS:" << std::endl \
		<< "\tName: " << Form.getName() << std::endl \
		<< "\tGrade required to sign: " << Form.getRequiredGradeToSign() << std::endl \
		<< "\tGrade required to execute: " << Form.getRequiredGradeToExecute() << std::endl \
		<< "\tIs signed: " << Form.getSigned() << std::endl;
	return os;
}