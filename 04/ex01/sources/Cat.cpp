#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &copy) 
{
	std::cout << "Cat constructor copy called"	<< std::endl;
	brain = new Brain(*copy.get_brain());
	type = copy.getType();
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
	{
		delete brain;
		brain = new Brain(*copy.get_brain());
		type = copy.getType();
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Miawww Miawww" << std::endl;
}

Brain* Cat::get_brain(void) const
{
	return brain;
}