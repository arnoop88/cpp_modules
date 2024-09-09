#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form::Form("RobotomyRequestForm", 72, 45), _target("someone"){}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form::Form("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): Form::Form(other), _target(other._target){}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void RobotomyRequestForm::beExecuted() const
{
	int success;

	std::srand(std::time(0));
	success = std::rand() % 2;
	std::cout << "BRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	if (success)
		std::cout << _target << " has been robotomized 🤖" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
