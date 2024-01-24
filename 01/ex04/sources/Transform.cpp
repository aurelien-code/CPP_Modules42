#include "Transform.hpp"
#include <iostream>
#include <fstream>

Transform::Transform(std::string file_path, std::string s1, std::string s2)
{
	_file_path = file_path;
	_s1 = s1;
	_s2 = s2;
	return;
}

Transform::~Transform(void)
{
	return;
}

std::string Transform::_replace_in_line(std::string line)
{
	std::size_t pos = 0;
	std::string new_line = "";
	
	while (pos != std::string::npos)
	{
		pos = line.find(_s1);
		if (pos != std::string::npos)
		{
			new_line += line.substr(0, pos);
			new_line += _s2;
			line = line.substr(pos + _s1.length());
		}
	}
	if (line.length() > 0)
	{
		new_line += line;
	}
	return (new_line);
}

void Transform::replace(void)
{
	std::string line;
	std::ifstream in_file(_file_path.c_str());
	std::ofstream out_file((_file_path + ".replace").c_str());
	std::size_t pos = 0;

	if (!in_file.is_open())
	{
		std::cout << "Error: could not open in_file" << std::endl;
		return;
	}
	while (getline(in_file, line))
	{
		pos = line.find(_s1);
		out_file << _replace_in_line(line) << std::endl;
	}
	in_file.close();
	out_file.close();
}
