#ifndef __DOG_HPP__
# define __DOG_HPP__

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string _type;

	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		void makeSound() const;
		std::string getType() const;
};

#endif
