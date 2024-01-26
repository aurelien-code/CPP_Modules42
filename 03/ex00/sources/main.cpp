#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Erouck");
	ClapTrap clap_bis("Zozivion");

	clap.attack("Zozivion");
	clap_bis.takeDamage(11);
	clap_bis.getHitpoints();

	return (0);
}
