#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("random", 100, 100, 30)
{
	std::cout << _name << "(FT) created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << _name << "(FT) created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy._name)
{
	std::cout << "FT copy constructor called" << std::endl;
	operator=(copy);
}

FragTrap::~FragTrap()
{
	std::cout << _name << "(FT) destroyed" << std::endl;
}

void FragTrap::highFive()
{
	std::cout << _name << " wants to high five! 🖐" << std::endl;
}
