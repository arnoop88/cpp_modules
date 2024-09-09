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

Bureaucrat::Bureaucrat(Bureaucrat const & other): _name(other._name), _grade(other._grade){}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
	if (this != &other)
		_grade = other._grade;
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

void Bureaucrat::signForm(Form & f)
{
	if (_grade > f.getSign())
		std::cout << _name << " couldn't sign because ";
	else if (f.getSigned())
		std::cout << _name << " couldn't sign because it is alredy signed" << std::endl;
	else
		std::cout << _name << " signed " << f.getName() << std::endl;
	f.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream & operator<<(std::ostream & out, Bureaucrat & other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return out;
}
