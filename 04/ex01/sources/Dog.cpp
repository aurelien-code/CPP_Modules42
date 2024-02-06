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
	brain = new Brain(*copy.get_brain());
	type = copy.getType();
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		delete brain;
		brain = new Brain(*copy.get_brain());
		type = copy.getType();
	}
	return *this;
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

Brain* Dog::get_brain(void) const
{
	return brain;
}