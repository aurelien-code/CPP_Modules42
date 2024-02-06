#include <iostream>
#include "ClapTrap.hpp"

# define GREEN	"\033[32m"
# define WHITE	"\033[37m"

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

	//Show HP of everyone
	zoz.showHitpoints();
	erik.showHitpoints();
	rodo.showHitpoints();
	std::cout << GREEN << "~~~~~~~~Zoz attak erik~~~~~~~~~~~" << WHITE << std::endl;
	
	//Zoz attak erik
	zoz.attack("Erouck");
	erik.takeDamage(0);
	erik.showHitpoints();
	std::cout << GREEN << "~~~~~~~Erik counter attack~~~~~~~~~~~~" << WHITE << std::endl;

	//Erik counter attack
	erik.attack("Zoz");
	zoz.takeDamage(10);
	zoz.showHitpoints();
	std::cout << GREEN << "~~~~~Zoz tries to repair himself~~~~~~~~~~~~~~" << WHITE << std::endl;

	//Zoz tries to repair himself
	zoz.beRepaired(10);
	std::cout << GREEN  << "~~~~~~~Rodo attak erik~~~~~~~~~~~~" <<  WHITE << std::endl;

	//Rodo attak erik
	rodo.attack("Erouck");
	erik.takeDamage(9);
	erik.showHitpoints();
	std::cout << GREEN << "~~~~~~Erik repairs himself ~~~~~~~~~~~~~" << WHITE << std::endl;

	//Erik repairs himself 
	erik.beRepaired(9);
	erik.showHitpoints();
	std::cout << GREEN << "~~~~~~Erick attak rodolph~~~~~~~~~~~~~" << WHITE << std::endl;

	//Erick attak rodolph
	erik.attack("Rodolph");
	rodo.takeDamage(9);
	rodo.showHitpoints();
	std::cout << GREEN << "~~~~~~Erik hard attak rodo and rodo tries to attackback~~~~~~~~~~~~~" << WHITE <<  std::endl;

	//Erik hard attak rodo and rodo tries to attackback
	erik.attack("Rodolph");
	rodo.takeDamage(11);
	rodo.attack("Erouck");
	std::cout << "~~~~~~~~~~~~~~~~~~~" << std::endl;

	return (0);
}
