#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal	*animal_array[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal_array[i] = new Dog();
		else
			animal_array[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animal_array[i];
	
	std::cout << std::endl << "--- deep copy ---" << std::endl << std::endl;
	Dog a;
	Cat b;

	Dog & a_ref = a;
	Cat & b_ref = b;

	std::cout << std::endl << "--- creating copies ---" << std::endl << std::endl;
	Dog a_copy(a_ref);
	Cat b_copy(b_ref);

	Dog & a_copy_ref = a_copy;
	Cat & b_copy_ref = b_copy;

	a_copy.makeSound();
	b_copy.makeSound();
	a_copy_ref.makeSound();
	b_copy_ref.makeSound();
}
