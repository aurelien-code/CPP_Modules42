#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap erouk_clap("Erouck");
	ClapTrap zozi_clap("Zozivion");

	erouk_clap.attack("Zozivion");
	zozi_clap.takeDamage(erouk_clap.getAttackDamage());
	zozi_clap.getHitpoints();

	ScavTrap scav("Jerem");
	scav.guardGate();

	FragTrap frag("Daniel");
	frag.highFivesGuys();
	frag.attack("Jerem");
	scav.takeDamage(frag.getAttackDamage());
	return (0);
}
