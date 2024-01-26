#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{

	//Throw an error because it's abstract
	// const AAnimal* meta = new AAnimal();
	// meta->makeSound();

	// delete meta;

	// Others same test as previous
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

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

	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_j;

	const int size = 10;
    AAnimal** animals = new AAnimal*[size];

    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "AAnimal type = " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;

	const AAnimal* t = new Dog();
	const AAnimal* x = new Cat();
	delete t;//should not create a leak
	delete x;

    return 0;
}
