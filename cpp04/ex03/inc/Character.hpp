#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <iostream>
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character & ref);
		Character & operator=(const Character & ref);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria* getMateria(int idx);
};

#endif
