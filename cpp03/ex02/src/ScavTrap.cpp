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

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in Gate keeper mode 🛡" << std::endl;
}
