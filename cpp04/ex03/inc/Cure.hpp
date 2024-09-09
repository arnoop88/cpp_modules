#ifndef __CURE_HPP__
# define __CURE_HPP__

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string _type;
	public:
		Cure();
		~Cure();
		Cure(const Cure & ref);
		Cure & operator=(const Cure & ref);

		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
