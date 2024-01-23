#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
	if (name.empty()) {
		std::cout << "Have you ever seen an unamed zombie ? Default name given" << std::endl;
		_name = "Boris the Zombie";
	}
	else {
		_name = name;
	}
}

Zombie::~Zombie(void) {
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
