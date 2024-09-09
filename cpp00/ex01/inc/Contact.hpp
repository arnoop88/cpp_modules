#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <climits>

class Contact
{
	private:
		std::string	fname;
		std::string	lname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_darkest_secret(void) const;
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nickname(std::string str);
		void		set_phone_number(std::string str);
		void		set_darkest_secret(std::string str);
};

#endif