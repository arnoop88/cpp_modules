#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "Created " << _name << "(B)" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destroyed " << _name << "(B)" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " attacks with her fist" << std::endl;
	else
		std::cout << _name << " attacks with her " << _weapon->getType() << std::endl;
}
