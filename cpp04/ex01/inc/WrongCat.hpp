#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string _type;

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& copy);
		void makeSound() const;
		std::string getType() const;
};

#endif
