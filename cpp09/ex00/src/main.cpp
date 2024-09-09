#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid arguments.\nTry " << argv[0] << " [file]" << std::endl;
		return 1;
	}
	std::ifstream infile;
	infile.open(((std::string)argv[1]).c_str());
	if (infile.fail())
	{
		std::cerr << "Couldn't open " << argv[1] << std::endl;
		return 1;
	}
	std::vector<std::pair<std::string, double> > vector1;
	parse(infile, vector1, 3);
	infile.close();
	infile.open(((std::string)"data.csv").c_str());
	if (infile.fail())
	{
		std::cerr << "Couldn't open data.csv" << std::endl;
		return 1;
	}
	std::vector<std::pair<std::string, double> > vector2;
	parse(infile, vector2, 1);
	output(vector1, vector2);
	return 0;
}
