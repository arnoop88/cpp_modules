#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Insert two numbers at least" << std::endl;
		return 1;
	}
	PmergeMe PmergeMe(argv);
}
