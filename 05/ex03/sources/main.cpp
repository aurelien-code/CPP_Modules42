#include <iostream>
#include <AForm.hpp>
#include "Intern.hpp"

int	main( void )
{
    Intern  someRandomIntern;
    AForm*   rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    delete rrf;
	return (0);
}