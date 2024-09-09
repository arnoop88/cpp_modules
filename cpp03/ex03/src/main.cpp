#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap CP("Clappy");
	ScavTrap SP("Scravy");
	FragTrap FT("Fraggy");
	DiamondTrap DT("Dia");
	DiamondTrap clone(DT);

	DT.attack(CP.getName());
	CP.takeDamage(DT.getAd());
	FT.highFive();
	CP.beRepaired(99);
	SP.attack(CP.getName());
	CP.takeDamage(SP.getAd());
	DT.whoAmI();
	clone.whoAmI();

	return 0;
}
