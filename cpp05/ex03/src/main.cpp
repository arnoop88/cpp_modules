#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat a("Jhon", 1);
		Bureaucrat b("Kin", 150);
		Bureaucrat c("Tom", 42);
		Form *f;
		ShrubberyCreationForm f1;
		RobotomyRequestForm f2("Kin");
		PresidentialPardonForm f3("Jean");
		Intern intern;
	
		std::cout << a << b << c << std::endl;
		f = intern.makeForm("presidential pardon", "Mike");
		a.signForm(*f);
		a.executeForm(*f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
