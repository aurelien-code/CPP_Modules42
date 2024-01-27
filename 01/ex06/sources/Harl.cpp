#include <string>
#include <iostream>
#include "Harl.hpp"

typedef void (Harl::*f)(void);

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG] love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::complain(std::string level)
{
	int complaining_level = 0;
	
	LevelFunc levels[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i].level)
		{
			complaining_level = i;
		}
	}
	std::cout << "cpl_lvl = " << complaining_level << std::endl;
	switch (complaining_level)
	{
		case 0:
			(this->*(levels[0].func))();
			(this->*(levels[1].func))();
			(this->*(levels[2].func))();
			(this->*(levels[3].func))();
			break;
		case 1:
			(this->*(levels[1].func))();
			(this->*(levels[2].func))();
			(this->*(levels[3].func))();
			break;
		case 2:
			(this->*(levels[2].func))();
			(this->*(levels[3].func))();
			break;
		case 3:
			(this->*(levels[3].func))();
			break;
		default:
			break;
	}
}