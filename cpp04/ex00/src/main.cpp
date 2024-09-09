#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const WrongAnimal* animal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	const Animal* dog = new Dog();

	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	delete animal;
	delete cat;
	delete dog;

	return 0;
}
