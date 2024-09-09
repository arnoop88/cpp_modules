#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <iostream>

class Weapon
{
	public:

		Weapon(std::string name);
		~Weapon();

		const std::string &getType(void);
		void	setType(std::string name);

	private:
		std::string _type;
};

#endif
