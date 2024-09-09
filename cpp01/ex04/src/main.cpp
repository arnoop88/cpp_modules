#include <iostream>
#include <fstream>

int	replace(std::string str, char **argv)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open(((std::string)argv[1] + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Error: cannot create " << argv[1] << ".replace" << std::endl;
		return 1;
	}
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (i == pos)
		{
			outfile << argv[3];
			i += (int)((std::string)argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	return 0;
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::string		str;
	char			c;

	if (argc != 4)
	{
		std::cout << "Invalid parameters\nUsage: ./Replace [infile] [what_to_replace] [what_to_replace_to]" << std::endl;
		return 1;
	}
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Error: cannot open " << argv[1] << std::endl;
		return 1;
	}
	while (!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	return replace(str, argv);
}