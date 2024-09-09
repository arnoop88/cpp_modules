#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const & other)
{
	*this = other;
}

Intern const &Intern::operator=(Intern const & other)
{
	(void)other;
	return *this;
}

static Form *makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static Form *makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static Form *makePresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string const &name, std::string const &target)
{
	Form *(*forms[])(const std::string &target) = {&makeShrubbery, &makeRobotomy, &makePresidential};
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return forms[i](target);
		}
	}
	throw FormDoesNotExist();
	return NULL;
}

const char *Intern::FormDoesNotExist::what() const throw()
{
	return "No form matches this name";
}
