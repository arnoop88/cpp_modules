#include "Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

std::string	Contact::get_fname(void) const
{
	return (this->fname);
}

std::string	Contact::get_lname(void) const
{
	return (this->lname);
}

std::string	Contact::get_nickname(void) const
{
	return (this->nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}

void	Contact::set_fname(std::string str)
{
	this->fname = str;
}

void	Contact::set_lname(std::string str)
{
	this->lname = str;
}

void	Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void	Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}
