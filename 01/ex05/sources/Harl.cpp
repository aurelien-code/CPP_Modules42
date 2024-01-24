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
			(this->*(levels[i].func))();
			return;
		}
	}
}