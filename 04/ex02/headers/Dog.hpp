#include "AAnimal.hpp"
#include "Brain.hpp"
class Dog: public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		~Dog();
		void makeSound() const;
		Brain* get_brain(void) const;

};