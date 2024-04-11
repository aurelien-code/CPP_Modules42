#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	private:
		const std::string _name;
		const int _requiredGradeToExecute;
		const int _requiredGradeToSign;
		bool _signed;
	
	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int GradeToExecute);
		Form(const Form &copy);
		Form &operator=(const Form &ref);
		~Form();
		std::string	getName() const;
		int			getRequiredGradeToSign() const;
		int			getRequiredGradeToExecute() const;
		bool		getSigned() const;
		bool		beSigned(Bureaucrat &bureaucrat);
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] Grade is too low to sign this form";
				}
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] Grade is too high to sign this form";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif