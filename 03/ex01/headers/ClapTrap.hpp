#include <string>

class ClapTrap
{
	protected:
		std::string _name;
		int _hitpoints;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int ep, int ad);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &copy);
		void getHitpoints() const;
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
};
