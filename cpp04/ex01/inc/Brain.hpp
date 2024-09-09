#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	
	public:
		Brain();
		~Brain();
		Brain(const Brain& ref);
		Brain &operator=(const Brain& ref);
		void setIdea(unsigned int i, std::string idea);
		std::string getIdea(unsigned int i);
};

#endif
