#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) , _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getRequiredGrade(), other.getExecutedGrade()), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void) other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
	std::string outputFileName = _target + "_shrubbery";
	std::ofstream fileout(outputFileName.c_str());
	if (!fileout)
	{
		std::cerr << "|--- Failed to create a file ---|" << std::endl;
		std::exit(1);
	}
	fileout << "        *              *              *\n";
	fileout << "       ***            ***            ***\n";
	fileout << "      *****          *****          *****\n";
	fileout << "     *******        *******        *******\n";
	fileout << "    *********      *********      *********\n";
	fileout << "       |||            |||            |||\n";
	fileout << "       |||            |||            |||\n";
	fileout << "\n";
	fileout << "          *                 *                 *\n";
	fileout << "         ***               ***               ***\n";
	fileout << "        *****             *****             *****\n";
	fileout << "       *******           *******           *******\n";
	fileout << "      *********         *********         *********\n";
	fileout << "     ***********       ***********       ***********\n";
	fileout << "         |||               |||               |||\n";
	fileout << "         |||               |||               |||\n";
	std::cout << "|--- File has been created successfully ---|" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() >= 137)
		throw (GradeTooLowException());
	else if (!getIsSigned())
		throw (FormNotSignedException());
	else
		action();
}