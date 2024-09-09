#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	_type = "animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	_type = copy._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	_type = copy._type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "(animal noises)" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
