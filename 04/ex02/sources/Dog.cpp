#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copy) 
{
	std::cout << "Dog constructor copy called"	<< std::endl;
	if (this != &copy)
	{
		type = copy.getType();
		brain = new Brain();
		*brain = *copy.brain;
	}
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		type = copy.getType();
        
        delete brain;        
        if (copy.brain) {
            brain = new Brain(*copy.brain);
        } else {
            brain = 0;
        }
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf" << std::endl;
}