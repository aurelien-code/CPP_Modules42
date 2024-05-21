#include "Bureaucrat.hpp"
#include "stdexcept"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
    {
		this->_grade = ref.getGrade();
    }
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
