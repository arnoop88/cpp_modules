#include "Weapon.hpp"

Weapon::Weapon(std::string name): _type(name)
{
	std::cout << _type << " created" << std::endl;
}

Weapon::~Weapon(void){}

const std::string &Weapon::getType(void)
{
	return _type;
}

void	Weapon::setType(std::string name)
{
	_type = name;
}
