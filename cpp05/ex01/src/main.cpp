#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("Jhon", 1); // 0
		Bureaucrat b("Kin", 150); // 151
		Bureaucrat c("Tom", 42);
		Form r;
		Form i("importantForm", 3, 3);
	
		std::cout << a << b << c << r << i << std::endl;
		//b.signForm(i);
		b.signForm(r);
		a.signForm(i);
		a.signForm(r);
		std::cout << std::endl << a << b << c << r << i;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
