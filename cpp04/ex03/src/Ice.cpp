#include "Ice.hpp"

Ice::Ice(): _type("ice")
{
	AMateria::_type = "ice";
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destroyed" << std::endl;
}

Ice::Ice(const Ice & ref): AMateria(ref._type)
{
	_type = ref._type;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice & Ice::operator=(const Ice & ref)
{
	std::cout << "Ice assign operator called" << std::endl;
	_type = ref._type;
	return *this;
}

std::string const & Ice::getType() const
{
	return _type;
}

Ice* Ice::clone() const
{
	Ice *copy = new Ice;
	return copy;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ince bolt at " << target.getName() <<  " *" << std::endl;
}
