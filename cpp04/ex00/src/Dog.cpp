#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	_type = "dog 🐶";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& copy): Animal()
{
	_type = copy._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	_type = copy._type;
	Animal::operator=(copy);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

std::string Dog::getType() const
{
	return _type;
}
