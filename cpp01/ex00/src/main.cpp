#include "Zombie.hpp"

int	main(void)
{
	Zombie *Jaume = newZombie("Jaume");
	Jaume->announce();
	randomChump("pissRandom");
	delete Jaume;
	return (0);
}