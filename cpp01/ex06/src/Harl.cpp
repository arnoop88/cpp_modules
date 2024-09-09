#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love playing league! this game is so fun :D" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "My supp has c happens" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Why do i have 4 pigs on my team??" << std::endl;
	std::cout << "Can i have a human team for once riot pls" << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Nah man this game is so fkin cringe bro get me out" << std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	void		(Harl::*msg[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*msg[i])();
			return ;
		}
	}
}
