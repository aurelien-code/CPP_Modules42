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
	std::cout << GREEN << "~test array of animals~" << WHITE << std::endl;
	const int size = 5;
    Animal** animals = new Animal*[size];

    for (int i = 0; i < size; ++i) {
		if (i < size / 2)
        	animals[i] = new Dog();
		else
        	animals[i] = new Cat();
	}
    for (int i = 0; i < size; ++i) {
        std::cout << "Animal type = " << animals[i]->getType() << " and his sound is : ";
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;

	std::cout << GREEN << "~test leaks as showned in subject~" << WHITE << std::endl;
	const Animal* t = new Dog();
	const Animal* x = new Cat();
	delete t;//should not create a leak
	delete x;

	std::cout << GREEN << "~test deepcopies~" << WHITE << std::endl;
	Dog* d1 = new Dog();
	Dog* d2 = new Dog(*d1);
	delete d1;
	delete d2;

	std::cout << GREEN << "~test deepcopies 2~" << WHITE << std::endl;
	Dog* d3 = new Dog();
	Dog* d4 = d3;
	delete d3;
	delete d4;
    return 0;
}
