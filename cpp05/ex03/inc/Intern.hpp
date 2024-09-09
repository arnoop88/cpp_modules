#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const & other);
		Intern const &operator=(Intern const & other);

		Form *makeForm(std::string const &name, std::string const &target);

		class FormDoesNotExist : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
