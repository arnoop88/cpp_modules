#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	setWeapon(Weapon weapon);
		void	attack();

	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif
