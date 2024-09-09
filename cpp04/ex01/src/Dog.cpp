#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	_type = "dog 🐶";
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& copy): Animal()
{
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	_type = copy._type;
	delete _brain;
	_brain = new Brain(*copy._brain);
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
