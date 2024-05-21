
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;
    
    public:
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &copy);
        Form &operator=(const Form &ref);
        ~Form();

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool beSigned(Bureaucrat &bureaucrat);

        class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] A grade cannot be lower than 150";
				}
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] A grade cannot be higher than 1";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
#endif