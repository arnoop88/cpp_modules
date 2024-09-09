#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "cat 🐱";
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& copy): Animal()
{
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	_type = copy._type;
	delete _brain;
	_brain = new Brain(*copy._brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::getType() const
{
	return _type;
}
