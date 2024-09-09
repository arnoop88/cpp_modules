#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character(): _name("random")
{
	std::cout << _name << " has born" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << _name << " has born" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << _name << " has died" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character::Character(const Character & ref): _name(ref._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << _name << " has been cloned" << std::endl;
}

Character & Character::operator=(const Character & ref)
{
	_name = ref._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character assign operator called" << std::endl;
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			std::cout << m->getType() << " equiped on slot " << i << std::endl;
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	if (_inventory[idx])
		std::cout << _inventory[idx]->getType() << " unequipped" << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Empty slot" << std::endl;
}

AMateria* Character::getMateria(int idx)
{
	return _inventory[idx];
}
