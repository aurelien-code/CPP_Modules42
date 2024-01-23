#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name) {
	_weapon = 0;
	return;
}

HumanB::~HumanB(void) {
	return;
}

void HumanB::attack(void) {
	if (!_weapon)
		std::cout << _name << " attacks without a weapon" << std::endl;
	else
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	return;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
	return;
}