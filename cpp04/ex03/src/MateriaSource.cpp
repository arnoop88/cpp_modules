#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_spellbook[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_spellbook[i])
			delete _spellbook[i];
}

MateriaSource::MateriaSource(const MateriaSource & ref)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (ref._spellbook[i])
			_spellbook[i] = ref._spellbook[i]->clone();
		else
			_spellbook[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (_spellbook[i])
			delete _spellbook[i];
		if (ref._spellbook[i])
			_spellbook[i] = ref._spellbook[i]->clone();
		else
			_spellbook[i] = NULL;
	}
	std::cout << "Character assign operator called" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_spellbook[i])
		{
			std::cout << m->getType() << " learned in page " << i << std::endl;
			_spellbook[i] = m;
			return;
		}
	}
	std::cout << "Spellbook has no more pages" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_spellbook[i] && _spellbook[i]->getType() == type)
			return _spellbook[i]->clone();
	std::cout << "Unknown materia" << std::endl;
	return NULL;
}
