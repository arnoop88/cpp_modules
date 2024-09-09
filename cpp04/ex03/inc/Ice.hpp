#ifndef __ICE_HPP__
# define __ICE_HPP__

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string _type;
	public:
		Ice();
		~Ice();
		Ice(const Ice & ref);
		Ice & operator=(const Ice & ref);

		std::string const & getType() const;
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
