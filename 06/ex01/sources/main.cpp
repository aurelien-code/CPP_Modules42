#include <iostream>
#include "Serializer.hpp"

void compareData(Data *d1, Data *d2)
{
	std::cout << "data:" << std::endl;
	std::cout << "\taddress: " << d1 << std::endl;
	std::cout << "\tn: " << d1->n << std::endl;
	std::cout << "\tstart: " << d1->s1 << std::endl;
	std::cout << "\tend: " << d1->s2 << std::endl;
	std::cout << "check:" << std::endl;
	std::cout << "\taddress: " << d2 << std::endl;
	std::cout << "\tn: " << d2->n << std::endl;
	std::cout << "\tstart: " << d2->s1 << std::endl;
	std::cout << "\tend: " << d2->s2 << std::endl;
	std::cout << "data and 2 are "
			  << (d1 == d2 ? "equal" : "not equal") << std::endl;
}

int main()
{
	Data *data;
	Data *check;

	data = new Data;
	data->n = 2;
	data->s1 = "Hello World";
	data->s2 = "Bonjour le monde";
	check = Serializer::deserialize(Serializer::serialize(data));
	compareData(data, check);
	delete data;
	return (0);
}
