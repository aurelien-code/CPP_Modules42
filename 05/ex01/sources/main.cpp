#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define YELLOW "\x1B[33m"
#define WHITE "\x1B[37m"

void testBureaucratCanSignForm()
{
	try
	{
		Bureaucrat bob("Bob", 30);
		Form formB("FormB", 40, 20);

		std::cout << bob << std::endl;
		std::cout << formB << std::endl;

		// should be ok
		bob.signForm(formB);

		std::cout << formB << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testBureaucratCannotSignForm()
{
	try
	{
		Bureaucrat alice("Alice", 60);
		Form formC("FormC", 50, 30);

		std::cout << alice << std::endl;
		std::cout << formC << std::endl;

		// should be Grade too low
		alice.signForm(formC);

		std::cout << formC << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testFormGradeTooHighException()
{
	try
	{
		// should be grade too high
		Form formD("FormD", 0, 30); 
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testFormGradeTooLowException()
{
	try
	{
		// grade too low 
		Form formE("FormE", 160, 30); 
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testSigningMultipleForms()
{
	try
	{
		Bureaucrat charlie("Charlie", 25);
		Form formF("FormF", 30, 20);
		Form formG("FormG", 20, 10);

		std::cout << charlie << std::endl;
		std::cout << formF << std::endl;
		std::cout << formG << std::endl;

		// normally ok
		charlie.signForm(formF);
		charlie.signForm(formG); 

		std::cout << formF << std::endl;
		std::cout << formG << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << YELLOW <<  "Test 1: Bureaucrat Can Sign Form" << WHITE << std::endl;
	testBureaucratCanSignForm();
	std::cout << std::endl;

	std::cout << YELLOW << "Test 2: Bureaucrat Cannot Sign Form" << WHITE << std::endl;
	testBureaucratCannotSignForm();
	std::cout << std::endl;

	std::cout << YELLOW << "Test 3: Form Grade Too High Exception" << WHITE << std::endl;
	testFormGradeTooHighException();
	std::cout << std::endl;

	std::cout << YELLOW << "Test 4: Form Grade Too Low Exception" << WHITE << std::endl;
	testFormGradeTooLowException();
	std::cout << std::endl;

	std::cout << YELLOW << "Test 5: Signing Multiple Forms" << WHITE << std::endl;
	testSigningMultipleForms();
	std::cout << std::endl;
	return (0);
}