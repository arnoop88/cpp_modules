#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _weapon(weapon)
{
	std::cout << "Created " << _name << "(A)" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destroyed " << _name << "(A)" << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	_weapon = weapon;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
