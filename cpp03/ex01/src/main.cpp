#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("Nami");
	ClapTrap b("Soraka");
	ScavTrap c("Draven");
	ScavTrap d(c);

	d.setName("Kalista");
	a.attack(c.getName());
	c.takeDamage(a.getAd());
	b.attack(c.getName());
	c.takeDamage(b.getAd());
	c.attack(b.getName());
	b.takeDamage(c.getAd());
	a.beRepaired(1);
	b.beRepaired(2);
	d.attack(c.getName());
	c.takeDamage(d.getAd());
	c.beRepaired(5);
	d.guardGate();

	return 0;
}
