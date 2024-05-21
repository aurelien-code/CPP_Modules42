
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &ref);
		~Bureaucrat();
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] Bureaucrat grade cannot be lower than 150";
				}
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] Bureaucrat grade cannot be higher than 1";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif