#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Erouck");
	ClapTrap clap_bis("Zozivion");

	clap.attack("Zozivion");
	clap_bis.takeDamage(11);
	clap_bis.getHitpoints();

	ScavTrap scav("Jerem");
	scav.guardGate();
	return (0);
}
