#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constuctor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destuctor called" << std::endl;
}

Brain::Brain(const Brain& ref)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ref._ideas[i];
	std::cout << "Brain copy constuctor called" << std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ref._ideas[i];
	return *this;
}

void Brain::setIdea(unsigned int i, std::string idea)
{
	if (i > 99)
		return ;
	_ideas[i] = idea;
}

std::string Brain::getIdea(unsigned int i)
{
	if (i > 99)
		return "";
	return _ideas[i];
}
