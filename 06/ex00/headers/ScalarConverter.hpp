#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <cctype>
# include <climits>
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

    public:
        static void convert(const std::string &str);
};

#endif