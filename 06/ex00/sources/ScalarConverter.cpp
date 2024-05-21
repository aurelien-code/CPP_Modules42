#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
    bool        		is_infinity = false;
    bool       			is_possible = true;
	bool				is_displayable = true;
	char				character;
    double     			dec_part;
	int					int_part;
    float      			float_part;
    std::string 		special_cases[6] = {
        "+inf",
        "-inf",
        "+inff",
        "-inff",
        "nan",
        "nanf"
    };
    std::stringstream	stream(str);
    
    for (int i = 0; i < 6; i++)
    {
        if (str == special_cases[i])
            is_infinity = true;
    }

    if (is_infinity)
    {
        if (str == special_cases[0] || str == special_cases[1])
        {
            dec_part = std::numeric_limits<double>::infinity();
			float_part = std::numeric_limits<float>::infinity();
        }
        else if (str == special_cases[2] || str == special_cases[3])
        {
            dec_part = -std::numeric_limits<double>::infinity();
			float_part = -std::numeric_limits<float>::infinity();
        }
        else
        {
            dec_part = std::numeric_limits<double>::quiet_NaN();
			float_part = std::numeric_limits<float>::quiet_NaN();
        }
    }
    else if (str.find('.') != str.npos && str.find('f') == str.length() - 1)
    {
        stream.clear();
		stream >> dec_part;
		is_possible = !stream.fail();

		if (is_possible)
		{
			float_part = static_cast<float>(dec_part);
			if (dec_part <= INT_MAX && dec_part >= INT_MIN)
			{
				int_part = static_cast<int>(dec_part);
				is_displayable = (dec_part > 32 && dec_part < 255);
				if (is_displayable)
				{
					character = static_cast<char>(dec_part);
				}
			}
		}
    }
	else
	{
		if (std::isdigit(str[0]) || ((str[0] == '-' || str[0] == '+') && std::isdigit(str[1])))
		{
			stream.clear();
			stream >> int_part;
			is_possible = !stream.fail();
			is_displayable = (is_possible && int_part > 32 && int_part < 255);
			if (is_displayable)
				character = static_cast<char>(int_part);
		}
		else if (str.length() == 1)
		{
			stream.clear();
			stream >> character;
			is_possible = !stream.fail();
			if (is_possible)
				int_part = static_cast<int>(character);
		}
		else
			is_possible = false;

		if (is_possible)
		{
			dec_part = static_cast<double>(int_part);
			float_part = static_cast<float>(int_part);
		}
	}

	std::cout << "char: ";
	if (!is_possible && !is_infinity)
		std::cout << "impossible";
	else if (!is_displayable)
		std::cout << "Non displayable";
	else
		std::cout << character;
	std::cout << std::endl << "int: ";
	if (!is_possible || is_infinity)
		std::cout << "impossible";
	else
		std::cout << int_part;
	std::cout << std::endl << "float: "
		<< std::fixed << std::setprecision(2);
	if (!is_possible)
		std::cout << "impossible";
	else
		std::cout << float_part << 'f';
	std::cout << std::endl << "double: ";
	if (!is_possible)
		std::cout << "impossible";
	else
		std::cout << dec_part;
	std::cout << std::endl;
}
