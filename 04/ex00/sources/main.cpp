#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//Do not forget to provide the maximum tests.
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_j = new WrongCat();

	std::cout << "j_type = " << j->getType() << " " << std::endl;
	std::cout << "i_type = " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << "### wrong animal from now ###" << std::endl;
	std::cout << "wj_type = " << wrong_j->getType() << " " << std::endl;
	wrong_j->makeSound();
	std::cout << "wm_type = " << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();
	meta->makeSound();
}
