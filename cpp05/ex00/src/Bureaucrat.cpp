#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("random"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(Bureaucrat const & ref): _name(ref._name), _grade(ref._grade){}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
	if (this != &ref)
		_grade = ref._grade;
	return *this;
}

std::string Bureaucrat::getName()
{
	return _name;
}

int Bureaucrat::getGrade()
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	_grade -= 1;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	_grade += 1;
	if (_grade > 150)
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream & operator<<(std::ostream & out, Bureaucrat & ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
	return out;
}
