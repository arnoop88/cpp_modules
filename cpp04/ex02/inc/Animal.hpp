#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal
{
	protected:
		std::string _type;
		
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
};

#endif
