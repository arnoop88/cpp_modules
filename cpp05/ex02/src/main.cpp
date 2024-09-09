#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("Jhon", 1);
		Bureaucrat b("Kin", 150);
		Bureaucrat c("Tom", 42);
		ShrubberyCreationForm f1;
		RobotomyRequestForm f2("Kin");
		PresidentialPardonForm f3("Jean");
	
		std::cout << a << b << c << std::endl;
		a.signForm(f3);
		a.executeForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
