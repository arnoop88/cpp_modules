#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		
		void	setWeapon(Weapon &weapon);
		void	attack();

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
