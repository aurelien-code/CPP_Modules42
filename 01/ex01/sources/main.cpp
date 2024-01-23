#include <iostream>
#include "Zombie.hpp"

int main()
{
	const int SIZE = 10;
	Zombie zombie("Z1");
	Zombie *t = zombie.zombieHorde(SIZE, "Z2");
	if (t == NULL) {
		return (1);
	}
	for (int i = 0; i < SIZE; i++) {
		t[i].announce();
	}
	delete[] t;
	return (0);
}