#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Sadge, ClapTrap " << this->_name << " exploded" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitpoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hitpoints <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " can't attack " << target << " because he is dead!" << std::endl;
		}
		else if (this->_energyPoints <= 0)
		{
			std::cout << "ClapTrap " << this->_name << " can't attack " << target << " because he is out of energy!" << std::endl;
		}	
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		if (amount > (unsigned int)this->_hitpoints)
		{
			this->_hitpoints = 0;
		}
		else
		{
			this->_hitpoints -= amount;
		}
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		if (this->_hitpoints + amount > 10)
		{
			this->_hitpoints = 10;
		}
		else
		{
			this->_hitpoints += amount;
		}
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
	}
}

void ClapTrap::getHitpoints() const
{
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitpoints << " hitpoints!" << std::endl;
}