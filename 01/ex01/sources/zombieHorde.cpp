#include "Zombie.hpp"
#include <iostream>

Zombie* Zombie::zombieHorde(int N, std::string name) {
	if (N <= 1) {
		std::cout << "Invalid number of zombies" << std::endl;
		return NULL;
	}
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
	}
	return horde;
}