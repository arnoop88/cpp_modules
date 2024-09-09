#include "AForm.hpp"

Form::Form(): _name("randomForm"), _sign(150), _exec(150), _signed(false){}

Form::Form(std::string name, int sign, int exec): _name(name), _sign(sign), _exec(exec), _signed(false)
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

Form::~Form(){}

Form::Form(Form const & other): _name(other._name), _sign(other._sign), _exec(other._exec), _signed(other._signed){}

Form const & Form::operator=(Form const & other)
{
	if (this != &other)
		return *this;
	return *this;
}

std::string Form::getName()
{
	return _name;
}

int Form::getSign()
{
	return _sign;
}

int Form::getExec()
{
	return _exec;
}

bool Form::getSigned()
{
	return _signed;
}

void Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() > _sign)
		throw GradeTooLowException();
	_signed = true;
}

void Form::execute(Bureaucrat & executor) const
{
	if (!_signed)
	{
		std::cout << "Couldn't execute because ";
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _exec)
	{
		std::cout << "Couldn't execute because ";
		throw GradeTooLowException();
	}
	std::cout << executor.getName() << " executed " << _name << std::endl;
	beExecuted();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream & operator<<(std::ostream & out, Form & other)
{
	out << other.getName() << " requires grade " << other.getSign() << " to sign, " << other.getExec() << " to execute and it is ";
	if (!other.getSigned())
		out << "NOT ";
	out << "signed" << std::endl;
	return out;
}
