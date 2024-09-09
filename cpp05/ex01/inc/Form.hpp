#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _sign;
		const int _exec;
		bool _signed;
	public:
		Form();
		Form(std::string name, int sign, int exec);
		~Form();
		Form(Form const & other);
		Form & operator=(Form const & other);

		std::string getName();
		int getSign();
		int getExec();
		bool getSigned();

		void beSigned(Bureaucrat & b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream & out, Form & other);

#endif