#include <string>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
	 	virtual ~AAnimal();

		std::string getType() const;
		virtual void makeSound() const = 0;
};


#endif