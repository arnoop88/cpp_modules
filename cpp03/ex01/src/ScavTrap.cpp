#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("random", 100, 50, 20)
{
	std::cout << _name << "(ST) created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << _name << "(ST) created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy._name)
{
	*this = copy;
	std::cout << "ST copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << "(ST) destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	_name = copy._name;
	_health = copy._health;
	_ad = copy._ad;
	_stamina = copy._stamina;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (_health > 0 && _stamina > 0)
	{
		std::cout << "Scav " << _name << " attacks " << target << " dealing " << _ad << " damage 💥" << std::endl;
		_stamina--;
	}
	else if (_health <= 0)
		std::cout << "Scav " << _name << " is dead so he cant attack" << std::endl;
	else
		std::cout << "Scav " << _name << " has no energy" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Scav " << _name << " is now in Gate keeper mode 🛡" << std::endl;
}
