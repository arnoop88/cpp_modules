#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <climits>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact _contacts[8];
		int		_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	display_contact(int i);
};

#endif