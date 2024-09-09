#include "PhoneBook.hpp"
#include <unistd.h>

PhoneBook::PhoneBook(void)
{
	_index = 0;
	std::cout << "Empty phonebook created" << std::endl << "Use ADD, SEARCH or EXIT to do the respective action" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Contacts destroyed" << std::endl;
}

int my_stoi(const std::string& str) //std::stoi
{
    int result = 0;
    int sign = 1;
    size_t i = 0;
    while (isspace(str[i]))
        ++i;
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    while (isdigit(str[i])) {
        result = result * 10 + (str[i++] - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN) {
            throw std::out_of_range("my_stoi: Out of range");
        }
    }
    while (isspace(str[i]))
        ++i;
    if (i < str.length()) {
        throw std::invalid_argument("my_stoi: Invalid argument");
    }
    return result * sign;
}

std::string my_to_string(int number) //std::to_string
{
    std::string result;
    bool isNegative = false;
	
    if (number == 0)
        return "0";
    if (number < 0) {
        isNegative = true;
        number = -number;
    }
    while (number > 0) {
        result = char('0' + number % 10) + result;
        number /= 10;
    }
    if (isNegative)
        result = '-' + result;
    
    return result;
}

void	PhoneBook::add(void)
{
	std::string	str;

	std::cout << "First name: ";
	std::getline(std::cin, str);
	_contacts[_index].set_fname(str);
	std::cout << "Last name: ";
	std::getline(std::cin, str);
	_contacts[_index].set_lname(str);
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	_contacts[_index].set_nickname(str);
	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	_contacts[_index].set_phone_number(str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	_contacts[_index].set_darkest_secret(str);
	if (_index == 7)
		_index = 0;
	else
		_index++;
}

void	print_data(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << std::right << str.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << std::right << str;
}

void	print_row(std::string index, std::string fname, std::string lname, std::string nname)
{
	std::cout << "|";
	print_data(index);
	std::cout << "|";
	print_data(fname);
	std::cout << "|";
	print_data(lname);
	std::cout << "|";
	print_data(nname);
	std::cout << "|" << std::endl;
}

void	PhoneBook::display_contact(int i)
{
	if (i > 7 || _contacts[i].get_fname() == "")
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << _contacts[i].get_fname() << std::endl;
	std::cout << "Last name: " << _contacts[i].get_lname() << std::endl;
	std::cout << "Nickname: " << _contacts[i].get_nickname() << std::endl;
	std::cout << "Phone number: " << _contacts[i].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << _contacts[i].get_darkest_secret() << std::endl;
}

void	PhoneBook::search(void)
{
	int			i;
	std::string	str;
	
	i = -1;
	if (_contacts[0].get_fname() == "")
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	print_row("Index", "First name", "Last name", "Nickname");
	while (++i < 8 && _contacts[i].get_fname() != "")
		print_row(my_to_string(i), _contacts[i].get_fname(), //std::to_string
				_contacts[i].get_lname(), _contacts[i].get_nickname());
	std::cout << "Display contact: ";
	std::getline(std::cin, str);
	display_contact(my_stoi(str)); //std::stoi
}
