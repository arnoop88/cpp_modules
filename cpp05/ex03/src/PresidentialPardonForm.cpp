#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form::Form("PresidentialPardonForm", 25, 5), _target("someone"){}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form::Form("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): Form::Form(other), _target(other._target){}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
