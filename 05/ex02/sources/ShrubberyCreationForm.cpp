#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm(src)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

void ShrubberyCreationForm::doAction(void) const
{
    std::ofstream file;
    std::string shrubberyAscii;

    file.open((_target + "_shrubbery").c_str(), std::ios::app);
    if (!file)
    {
        std::cerr << "Unable to open file: " << _target << "_shrubbery" << std::endl;
        return;
    }

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\"  << std::endl;

    file.close();
}
