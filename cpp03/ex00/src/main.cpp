#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Nami");
	ClapTrap b("Soraka");

	//a.setAd(4);
	//b.setAd(3);

	a.attack(b.getName());
	b.takeDamage(a.getAd());
	b.attack(a.getName());
	a.takeDamage(b.getAd());
	a.beRepaired(1);
	b.beRepaired(2);
	a.attack(b.getName());
	b.takeDamage(a.getAd());
	b.attack(a.getName());
	a.takeDamage(b.getAd());
	a.attack(b.getName());
	b.takeDamage(a.getAd());
	b.attack(a.getName());
	a.takeDamage(b.getAd());
	a.beRepaired(1);
	b.beRepaired(2);
	a.attack(b.getName());
	b.takeDamage(a.getAd());
	b.attack(a.getName());

	return 0;
}
