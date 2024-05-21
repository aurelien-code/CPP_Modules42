
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;
    
    public:
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &ref);
        virtual ~AForm();

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void doAction(void) const = 0;

        class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] Grade is too low";
				}
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "[ERROR] Grade is too high";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif