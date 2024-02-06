#include <string>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	protected:
		std::string ideas[100];
		std::string idea;		
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();

};

#endif