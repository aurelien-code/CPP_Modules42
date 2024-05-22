#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data
{
	int			n;
	std::string	s1;
	std::string	s2;
};

class Serializer
{
	private:
		Serializer(void);
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
	
	public:
		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw); 
};

#endif