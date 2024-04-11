#include "Bureaucrat.hpp"
#include "stdexcept"

Bureaucrat::Bureaucrat(void)
{
	throw std::invalid_argument("Bureaucrat cannot be initialized without arguments");
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade)
{
	if (grade < 1 || grade > 150)
	{
		throw std::invalid_argument("Bureaucrat grade has to be in the range [1;150]");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref) // Protect against self-assignment
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
	{
		this->_grade--;
	}
	else
	{
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade < 150)
	{
		this->_grade++;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(bool status, std::string reason)
{
	if (!status)
	{
		std::cout << this->getName() << " cannot sign the form: " << reason << std::endl;
	}
	else
	{	
		std::cout << this->getName() << " signed the form \"" << reason << "\"" << std::endl;
	}
}