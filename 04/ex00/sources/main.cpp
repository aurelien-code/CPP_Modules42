#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define GREEN	"\033[32m"
# define WHITE	"\033[37m"

int main()
{
	std::cout << GREEN << "~test from subject~" << WHITE << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog_1 = new Dog();
	const Animal* cat_1 = new Cat();
	std::cout << "Animal/Dog type = " << dog_1->getType() << std::endl;
	std::cout << "Animal/Cat type = " << cat_1->getType() << std::endl;
	cat_1->makeSound();
	dog_1->makeSound();
	meta->makeSound();
	delete dog_1;
	delete cat_1;
	delete meta;

	std::cout << GREEN << "~test if types are ok~" << WHITE << std::endl;
	const Animal* meta_2 = new Animal("Crocodile");
	const Animal* dog_2 = new Dog();
	const Animal* cat_2 = new Cat();
	std::cout << "Animal(Crocodile) type = " << meta_2->getType() << std::endl;
	std::cout << "Animal(Dog) type = " << dog_2->getType() << std::endl;
	std::cout << "Animal(Cat) type = " << cat_2->getType() << std::endl;
	delete meta_2;
	delete cat_2;
	delete dog_2;

	std::cout << GREEN << "~test wrong animals~" << WHITE << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_j = new WrongCat();
	std::cout << "WrongMeta() type = " << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();
	std::cout << "WrongAnimal(Cat) type = " << wrong_j->getType() << " " << std::endl;
	wrong_j->makeSound();
	delete wrong_j;
	delete wrong_meta;
}
