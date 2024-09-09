#ifndef __CAT_HPP__
# define __CAT_HPP__

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string _type;
		Brain* _brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		void makeSound() const;
		std::string getType() const;
};

#endif
