#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	_type = "WrongCat 😼";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal()
{
	_type = copy._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	_type = copy._type;
	WrongAnimal::operator=(copy);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow'nt" << std::endl;
}

std::string WrongCat::getType() const
{
	return _type;
}
