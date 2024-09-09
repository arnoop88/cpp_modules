#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destroyed" << std::endl;
}

AMateria::AMateria(const AMateria & ref): _type(ref._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Some materia used on " << target.getName() << std::endl;
}
