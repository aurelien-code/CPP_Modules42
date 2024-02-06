#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	// Faire un recheck que ca fonctionne bien avant de push !!!!
	ClapTrap clap_daniel("Daniel");
	ClapTrap clap_zozi("Zozivion");
	ClapTrap clap_jean("Jean");
	ClapTrap clap_noname("");

	clap_daniel.attack("Zozivion");
	clap_zozi.takeDamage(10);
	clap_zozi.beRepaired(10);
	clap_zozi.attack("Jean");
	clap_jean.takeDamage(1);
	clap_jean.attack("");
	clap_noname.takeDamage(10);
	//MAKE MORE TESTS
	ClapTrap clap("Erouck");
	ClapTrap clap_bis("Zozivion");

	clap.attack("Zozivion");
	clap_bis.takeDamage(11);
	clap_bis.getHitpoints();

	return (0);
}
