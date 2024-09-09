#include "Cure.hpp"

Cure::Cure(): _type("cure")
{
	AMateria::_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destroyed" << std::endl;
}

Cure::Cure(const Cure & ref): AMateria(ref._type)
{
	_type = ref._type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure & Cure::operator=(const Cure & ref)
{
	std::cout << "Cure assign operator called" << std::endl;
	_type = ref._type;
	return *this;
}

std::string const & Cure::getType() const
{
	return _type;
}

Cure* Cure::clone() const
{
	Cure *copy = new Cure;
	return copy;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}
