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

	//d1 and d2 should have differents adresses
	std::cout << GREEN << "~test deepcopies copy op~" << WHITE << std::endl;
	Dog* d1 = new Dog();
	Dog* d2 = new Dog(*d1);
	std::cout << "Adress of d1 = " << &d1 << std::endl;
	std::cout << "Adress of d2 = " << &d2 << std::endl;
	std::cout << "Adress of d1.brain = " << (d1->get_brain()) << std::endl;
	std::cout << "Adress of d2.brain = " << (d2->get_brain()) << std::endl;
	delete d1;
	delete d2;
	
	//d5 and d6 should have differents adresses
	std::cout << GREEN << "~test deepcopies assign op heap~" << WHITE << std::endl;
	Dog* d5 = new Dog();
	Dog* d6 = new Dog();
	*d6 = *d5;
	std::cout << "Adress of d5 = " << &d5 << std::endl;
	std::cout << "Adress of d6 = " << &d6 << std::endl;
	std::cout << "Adress of d5.brain = " << (d5->get_brain()) << std::endl;
	std::cout << "Adress of d6.brain = " << (d6->get_brain()) << std::endl;
	delete d5;
	delete d6;

	//d3 and d4 should have differents adresses
	std::cout << GREEN << "~test deepcopies assign op stack~" << WHITE << std::endl;
	Dog d3;
	Dog d4 = d3;
	std::cout << "Adress of d3 = " << &d3 << std::endl;
	std::cout << "Adress of d4 = " << &d4 << std::endl;
	std::cout << "Adress of d3.brain = " << (d3.get_brain()) << std::endl;
	std::cout << "Adress of d4.brain = " << (d4.get_brain()) << std::endl;

    return 0;
}
