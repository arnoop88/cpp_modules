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
	std::cout << "ST copy constructor called" << std::endl;
	operator=(copy);
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << "(ST) destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << _name << " is now in Gate keeper mode 🛡" << std::endl;
}
