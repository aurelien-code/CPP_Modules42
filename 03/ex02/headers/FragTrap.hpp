#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
	
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();
		FragTrap &operator=(const FragTrap &copy);
		void highFivesGuys(void);
};