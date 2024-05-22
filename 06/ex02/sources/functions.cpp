#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    
    switch(random) {
        case 0:
            std::cout << "random == " << random << std::endl;
            return new A();
        case 1:
            std::cout << "random == " << random << std::endl;
            return new B();
        case 2:
            std::cout << "random == " << random << std::endl;
            return new C();
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A\n";
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B\n";
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C\n";
    }
}

void identify(Base& p) {
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    } 
    catch (std::exception& e) {}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch (std::exception& e) {}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch (std::exception& e) {}
}