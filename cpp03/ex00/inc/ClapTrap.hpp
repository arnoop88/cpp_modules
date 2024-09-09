#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>

class ClapTrap
{
	private:
		std::string  _name;
		int _health;
		int _stamina;
		int _ad;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName();
		unsigned int getAd();
		void setHealth(unsigned int amount);
		void setStamina(unsigned int amount);
		void setAd(unsigned int amount);
};

#endif
