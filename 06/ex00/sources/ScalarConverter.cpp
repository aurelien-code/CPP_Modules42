#include "ScalarConverter.hpp"

static void handle_infinity_cases(const std::string &str)
{
    const std::string	infinity_cases[6] = {"+inf","-inf","+inff","-inff","nan","nanf"};
	double				db_value = 0.0;
	float				float_value = 0.0f;
	bool				float_flag = false;

	std::cout << "char:\timpossible" << std::endl;
	std::cout << "int:\timpossible" << std::endl;
	
	if (str == infinity_cases[2] || str == infinity_cases[3] || str == infinity_cases[5])
		float_flag = true;

	if (str == infinity_cases[0] || str == infinity_cases[2])
	{
		db_value = std::numeric_limits<double>::infinity();
		float_value = std::numeric_limits<double>::infinity();
	}
	else if (str == infinity_cases[1] || str == infinity_cases[3])
	{
		db_value = -std::numeric_limits<double>::infinity();
		float_value = -std::numeric_limits<float>::infinity();
	}
	else
	{
		db_value = std::numeric_limits<double>::quiet_NaN();
		float_value = std::numeric_limits<float>::quiet_NaN();
	}
	std::cout << "float:\t" << float_value << (float_flag ? "f": "") << std::endl;
	std::cout << "double:\t" << db_value << std::endl;
}


static void handle_float_cases(const std::string &str)
{
	std::stringstream stream(str);
	double	db_part = 0.0;
	float	ft_part = 0.0f;
	int		it_part = 0;
	char	character = 0;
	bool	bigger_than_int = false;

	stream >> db_part;
	if (!stream.fail())
	{
		ft_part = static_cast<float>(db_part);
		if (db_part <= INT_MAX && db_part >= INT_MIN)
		{
			it_part = static_cast<int>(db_part);
			if (std::isprint(static_cast<char>(db_part)))
			{
				character = static_cast<char>(db_part);
			}
			else
				character = 0;
		}
		else
			bigger_than_int = true;
	}
	if (!character)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t" << character << std::endl;
	if (bigger_than_int)
		std::cout << "int:\tinput too large to handle in int" << std::endl;
	else
		std::cout << "int:\t" << it_part << std::endl;
	std::cout << "float:\t" << ft_part << "f" << std::endl;
	std::cout << "double:\t" << db_part << std::endl;
}

static void handle_double_cases(const std::string &str)
{
	std::stringstream stream(str);
	double	db_part = 0.0;
	float	ft_part = 0.0f;
	int		it_part = 0;
	char	character = 0;
	bool	bigger_than_int = false;
	stream >> db_part;
	if (!stream.fail())
	{
		ft_part = static_cast<float>(db_part);
		if (db_part <= INT_MAX && db_part >= INT_MIN)
		{
			it_part = static_cast<int>(db_part);
			if (std::isprint(static_cast<char>(db_part)))
			{
				character = static_cast<char>(db_part);
			}
			else
				character = 0;
		}
		else
			bigger_than_int = true;
	}
	if (!character)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t" << character << std::endl;
	if (bigger_than_int)
		std::cout << "int:\tinput too large to handle in int" << std::endl;
	else
		std::cout << "int:\t" << it_part << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "float:\t" << ft_part << "f" << std::endl;
	std::cout << "double:\t" << db_part << std::endl;
}

static void handle_other_cases(const std::string &str)
{
	bool        		is_infinity = false;
    bool       			is_possible = true;
	bool				is_displayable = true;
	char				character;
    double     			dec_part;
	int					int_part;
    float      			float_part;
    const std::string 	infinity_cases[6] = {"+inf","-inf","+inff","-inff","nan","nanf"};
    std::stringstream	stream(str);

	if (std::isdigit(str[0]) || ((str[0] == '-' || str[0] == '+') && std::isdigit(str[1])))
	{
		stream.clear();
		stream >> int_part;
		is_possible = !stream.fail();
		is_displayable = (is_possible && std::isprint(static_cast<char>(int_part)));
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

	std::cout << std::endl << "float: " << std::fixed << std::setprecision(2);
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

void ScalarConverter::convert(const std::string &str)
{
    const std::string 	infinity_cases[6] = {"+inf","-inf","+inff","-inff","nan","nanf"};
    
    for (int i = 0; i < 6; i++)
    {
        if (str == infinity_cases[i])
		{
			handle_infinity_cases(str);
			return ;
		}
    }

    if (str.find('.') != str.npos && str.find('f') == str.length() - 1)
    {
		handle_float_cases(str);
		return ;
    }
	else if (str.find('.') != str.npos)
	{
		handle_double_cases(str);
		return ;
	}
	else
	{
		handle_other_cases(str);
	}
}