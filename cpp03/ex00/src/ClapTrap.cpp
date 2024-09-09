#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("random"), _health(10), _stamina(10), _ad(0)
{
	std::cout << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _stamina(10), _ad(0)
{
	std::cout << _name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	_name = copy._name;
	_health = copy._health;
	_ad = copy._ad;
	_stamina = copy._stamina;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_health > 0 && _stamina > 0)
	{
		std::cout << _name << " attacks " << target << " dealing " << _ad << " damage 💥" << std::endl;
		_stamina--;
	}
	else if (_health <= 0)
		std::cout << _name << " is dead so he cant attack" << std::endl;
	else
		std::cout << _name << " has no energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_health -= amount;
	if (_health + (int)amount <= 0)
		std::cout << "bro.. 😔" << std::endl;
	else if (_health <= 0)
		std::cout << _name << " died 💀" << std::endl;
	else
		std::cout << _name << " is now " << _health << "hp" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health > 0 && _stamina > 0)
	{
		_health += amount;
		_stamina--;
		std::cout << _name << " repaired himself for " << amount << "hp and he is now " << _health << "hp" << std::endl;
	} 
	else if (!_health)
		std::cout << _name << " is dead so he cant repair himself" << std::endl;
	else
		std::cout << _name << " has no energy" << std::endl;
}

std::string ClapTrap::getName()
{
	return _name;
}

unsigned int ClapTrap::getAd()
{
	return _ad;
}

void ClapTrap::setHealth(unsigned int amount)
{
	_health = amount;
}

void ClapTrap::setStamina(unsigned int amount)
{
	_stamina = amount;
}

void ClapTrap::setAd(unsigned int amount)
{
	_ad = amount;
}
