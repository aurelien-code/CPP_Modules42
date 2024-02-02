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
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
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