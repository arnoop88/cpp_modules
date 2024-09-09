#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form::Form("ShrubberyCreationForm", 145, 137), _target("somewhere"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form::Form("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): Form::Form(other), _target(other._target){}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void ShrubberyCreationForm::beExecuted() const
{
	std::ofstream ofile;

	ofile.open((_target + "_shrubbery").c_str());
	if (ofile.fail())
	{
		std::cout << "Failed to open file." << std::endl;
		return;
	}
	ofile << TREE;
	ofile.close();
}
