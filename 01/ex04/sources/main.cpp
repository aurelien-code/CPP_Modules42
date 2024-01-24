#include "Transform.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	Transform transformation = Transform(argv[1], argv[2], argv[3]);
	transformation.replace();
}