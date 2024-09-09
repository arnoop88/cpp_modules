#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Jhon", 1); // 0
		Bureaucrat b("Kin", 150); // 151
		Bureaucrat c("Tom", 42);
	
		std::cout << a << b << c << std::endl;
		a.incrementGrade();
		b.decrementGrade();
		c.incrementGrade();
		std::cout << a << b << c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
