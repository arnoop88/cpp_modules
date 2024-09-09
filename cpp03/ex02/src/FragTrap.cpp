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
	*this = copy;
	std::cout << "FT copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << _name << "(FT) destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	_name = copy._name;
	_health = copy._health;
	_ad = copy._ad;
	_stamina = copy._stamina;
	return *this;
}

void FragTrap::highFive()
{
	std::cout << _name << " wants to high five! 🖐" << std::endl;
}
