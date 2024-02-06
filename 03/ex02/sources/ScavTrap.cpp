#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy._name)
{
	*this = copy;
	std::cout << "ScavTrap " << this->_name << " is born!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Sadge, ScavTrap " << this->_name << " exploded" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_hitpoints > 0 && this->_energyPoints > 0)
		std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
	else if (this->_hitpoints > 0 && this->_energyPoints <= 0)
		std::cout << this->_name << " is out of energy!" << std::endl;
	else
		std::cout << this->_name << " is already dead!" << std::endl;

}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitpoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hitpoints <= 0)
		{
			std::cout << "ScavTrap " << this->_name << " can't attack " << target << " because he is dead!" << std::endl;
		}
		else if (this->_energyPoints <= 0)
		{
			std::cout << "ScavTrap " << this->_name << " can't attack " << target << " because he is out of energy!" << std::endl;
		}	
	}
}