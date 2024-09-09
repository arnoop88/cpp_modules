#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		draven;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	if (argc != 2)
	{
		std::cout << "\033[0;93mHAHAHAXDXDXDXD has muted themselves and won't be able to type any messages in chat" << std::endl;
		return 1;
	}
	i = -1;
	while (++i < 4)
		if (levels[i] == argv[1])
			break ;
	switch (i)
	{
		case 0:
			draven.complain("DEBUG");
		case 1:
			draven.complain("INFO");
		case 2:
			draven.complain("WARNING");
		case 3:
			draven.complain("ERROR");
			break;
		default:
			std::cout << "\033[0;93mHAHAHAXDXDXDXD has muted themselves and won't be able to type any messages in chat" << std::endl;
	}
}
