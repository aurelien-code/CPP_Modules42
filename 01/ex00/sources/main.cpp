#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie zombie("Z1");
	Zombie zombie2("");

	zombie2.announce();
	zombie.announce();
	zombie.randomChump("Z3");
	Zombie *x = zombie.newZombie("Z4");
	x->announce();
	delete x;
	return (0);
}