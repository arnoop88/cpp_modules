#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon gun = Weapon("calibrum");
		HumanA aph("Aphelios", gun);
		aph.attack();
		gun.setType("severum");
		aph.attack();
	}
	{
		Weapon gun2 = Weapon("machine gun");
		HumanB jinx("Jinx");
		jinx.attack();
		jinx.setWeapon(gun2);
		jinx.attack();
		gun2.setType("rocket launcher");
		jinx.attack();
	}

}
