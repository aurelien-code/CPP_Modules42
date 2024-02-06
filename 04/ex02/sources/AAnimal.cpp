#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called" << std::endl;
	this->type = "";
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal constructor called" << std::endl;
	this->type = type;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = copy.type;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}

void AAnimal::makeSound(void) const
{
	std::cout << "" << std::endl;
}