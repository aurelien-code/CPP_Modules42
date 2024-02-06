#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " is born!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy._name)
{
	*this = copy;
	std::cout << "FragTrap " << this->_name << " is born!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Sadge, FragTrap " << this->_name << " exploded" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (this->_hitpoints > 0 && this->_energyPoints > 0)
		std::cout << "FragTrap " << this->_name << " is asking for high fives" << std::endl;
	else if (this->_hitpoints > 0 && this->_energyPoints <= 0)
		std::cout << this->_name << " is out of energy!" << std::endl;
	else
		std::cout << this->_name << " is already dead!" << std::endl;

}


void FragTrap::attack(const std::string &target)
{
	if (this->_hitpoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hitpoints <= 0)
		{
			std::cout << "FragTrap " << this->_name << " can't attack " << target << " because he is dead!" << std::endl;
		}
		else if (this->_energyPoints <= 0)
		{
			std::cout << "FragTrap " << this->_name << " can't attack " << target << " because he is out of energy!" << std::endl;
		}	
	}
}