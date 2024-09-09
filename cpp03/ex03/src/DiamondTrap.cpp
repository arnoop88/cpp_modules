#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("random_clap_name", 100, 50, 30), ScavTrap(), FragTrap()
{
	_name = "random";
	std::cout << _name << "(DT) created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap()
{
	_name = name;
	std::cout << _name << "(DT) created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy._name + "_clap_name"), ScavTrap(copy._name + "_clap_name"), FragTrap(copy._name + "_clap_name")
{
	std::cout << "DT copy constructor called" << std::endl;
	operator=(copy);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << "(DT) destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	ClapTrap::operator=(copy);
	_name = copy._name;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << ClapTrap::_name << ", but you can call me " << _name << std::endl;
}
