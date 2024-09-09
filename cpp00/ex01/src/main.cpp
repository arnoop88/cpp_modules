#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact[8];
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str != "EXIT")
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}